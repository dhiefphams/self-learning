use diesel;
use diesel::prelude::*;
use diesel::mysql::MysqlConnection;
use schema::heroes;

#[table_name = "heroes"]
#[derive(Serialize, Deserialize, Queryable, Insertable, AsChangeset)]
pub struct Hero {
    // Use option because input id can be none
    pub id: Option<i32>,
    pub name: String,
    pub identity: String,
    pub hometown: String,
    pub age: i32
}


impl Hero {

    /// Inser new hero into database
    /// also return the value inserted
    pub fn create(hero: Hero, connection: &MysqlConnection) -> Hero {
        use schema::heroes::dsl::{heroes, id};
        diesel::insert_into(heroes)
            .values(&hero)
            .execute(connection)
            .expect("Error create new hero");
        heroes.order(id.desc()).first(connection).unwrap()
    }

    /// Query all heroes
    pub fn read(connection: &MysqlConnection) -> Vec<Hero> {
        use schema::heroes::dsl::{heroes, id};
        heroes.order(id.asc()).load::<Hero>(connection).unwrap()
    }

    pub fn update(id: i32, hero: Hero, connection: &MysqlConnection) -> bool {
        diesel::update(heroes::table.find(id))
            .set(&hero)
            .execute(connection)
            .is_ok()
    }

    pub fn delete(id: i32, connection: &MysqlConnection) -> bool {
        diesel::delete(heroes::table.find(id)).execute(connection).is_ok()
    }
}

