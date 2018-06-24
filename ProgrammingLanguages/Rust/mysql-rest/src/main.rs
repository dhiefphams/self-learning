#![feature(plugin)]
#![plugin(rocket_codegen)]

#[macro_use]
extern crate rocket_contrib;
#[macro_use]
extern crate serde_derive;
#[macro_use]
extern crate diesel;

extern crate rocket;
extern crate r2d2;
extern crate r2d2_diesel;


use rocket_contrib::{Json, Value};

mod hero;
use hero::{Hero};
mod db;
mod schema;

#[post("/", data="<hero>")]
fn create(hero: Json<Hero>, connection: db::Connection) -> Json<Hero> {
   let insert = Hero { id: None, ..hero.into_inner() };
   Json(Hero::create(insert, &connection))
}

#[get("/")]
fn read(connection: db::Connection) -> Json<Value> {
    Json(json!(Hero::read(&connection)))
}

#[put("/<id>", data="<hero>")]
fn update(id: i32, hero: Json<Hero>, connection: db::Connection) -> Json<Value> {
    let update = Hero { id: Some(id), ..hero.into_inner() };
    Json(json!({
        "success": Hero::update(id, update, &connection)
    }))
}

#[delete("/<id>")]
fn delete(id: i32, connection: db::Connection) -> Json<Value> {
    Json(json!({
        "success": Hero::delete(id, &connection)
    }))
}

#[get("/<name>/<age>")]
fn hello(name: String, age: u8) -> String {
    format!("Hello, {} year old named {}!", age, name)
}

fn main() {
    rocket::ignite()
        .manage(db::connect())
        .mount("/hello", routes![hello])
        .mount("/heroes", routes![read])
        .mount("/hero", routes![create, update, delete])
        .launch();

}
