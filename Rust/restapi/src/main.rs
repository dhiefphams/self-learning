extern crate serde;
extern crate rustc_serialize;
extern crate jwt;
extern crate hyper;
extern crate crypto;

#[macro_use]
extern crate nickel;

#[macro_use]
extern crate serde_derive;

#[macro_use]
extern crate serde_json;

#[macro_use(bson, doc)]
extern crate bson;
extern crate mongodb;

// Nickel
use nickel::{Nickel, JsonBody, HttpRouter, Request, Response, MiddlewareResult, MediaType};
use nickel::status::StatusCode::{self, Forbidden};

// hyper
use hyper::header;
use hyper::header::{Authorization, Bearer};

//jwt
use std::default::Default;
use crypto::sha2::Sha256;
use jwt::{Header, Registerd, Token};

// Mongodb
use mongodb::{Client, ThreadedClient};
use mongodb::db::ThreadedDatabase;
use mongodb::error::Result as MongoResult;

// bson
use bson::{Bson, Document};
use bson::oid::ObjectId;

// rustc_serialize
use serde_json::value::Value;


#[derive(RustcDecodable, RustcEncodable)]
#[derive(Debug)]
struct User {
    firstname: String,
    lastname: String,
    email: String
}


fn main() {
    // create router
    let mut router = Nickel::router();

    //
    router.get("/users", middleware! { |request, mut response|
        // connecto to database
        let client = Client::connect("localhost", 27017)
            .ok().expect("Error establishing connection");
        let db = client.db("rust");
        let coll = db.collection("users");
        // create a cursor that finds all documents
        let mut cursor = coll.find(None, None).unwrap();

        // opening for the JSON string to te returned
        let mut data_result = "{\"data \": [".to_owned();
        
        for (i, result) in cursor.enumerate() {
            match get_data_string(result) {
                Ok(data) => {
                    let string_data = if i == 0 {
                        format!("{}", data)
                    } else {
                        format!("{},", data)
                    };

                    data_result.push_str(&string_data);
                },

                Err(e) => return response.send(format!("{}", e))
            }
        }

        // close the json string
        data_result.push_str("]}");

        // set the retuned type as json
        response.set(MediaType::Json);

        // send back the result
        format!("{}", data_result)
    });
    
    //
    router.post("/users", middleware! { |request, response|
        // accept a json string that correstponds to the user struct
        let user = request.json_as::<User>().unwrap();
        let firstname = user.firstname.to_string();
        let lastname = user.lastname.to_string();
        let email = user.email.to_string();
        
        // connecto to database
        let client = Client::connect("localhost", 27017)
            .ok().expect("Error establishing connection");
        let db = client.db("rust");
        // the users collections
        let coll = db.collection("users");

        // insert user
        match coll.insert_one(doc! {
            "firstname" => firstname,
            "lastname" => lastname,
            "email" => email
        }, None) {
            Ok(_) => (StatusCode::Ok, "Item Saved!"),
            Err(e) => return response.send(format!("{}", e))
        }
    });
    
    router.delete("/users/:id", middleware! { |request, response|
        // connect to database
        let client = Client::connect("localhost", 27017)
            .ok().expect("Error etablishing connection");
        
        let collection = client.db("rust").collection("users");
        // get object id from request params
        let user_id = request.param("id").unwrap();
        // convert userId string to ObjectId
        let id = match ObjectId::with_string(user_id) {
            Ok(objectId) => objectId,
            Err(e) => return response.send(format!("{}", e))
        };

        // start delete
        match collection.delete_one(doc! { "_id" => id }, None) {
            Ok(_) => (StatusCode::Ok, "Item deleted"),
            Err(e) => return response.send(format!("{}", e))
        }
    });

    // create and listen server
    let mut server = Nickel::new();

    server.utilize(router);
    server.listen("localhost:8081");
}

fn get_data_string(result: MongoResult<Document>) -> Result<Value, String> {
    match result {
        Ok(doc) => Ok(Bson::Document(doc).clone().into()),
        Err(e) => Err(format!("{}", e))
    }
}