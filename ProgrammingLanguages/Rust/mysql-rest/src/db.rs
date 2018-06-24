use std::ops::Deref;
use rocket::http::Status;
use rocket::request::{self, FromRequest};
use rocket::{Request, State, Outcome};

use r2d2;
use r2d2_diesel::ConnectionManager;

use diesel::mysql::MysqlConnection;

// we use r2d2 to manage our database connection pool instead of create new
// one for each request
pub type Pool = r2d2::Pool<ConnectionManager<MysqlConnection>>;
static DATABASE_URL: &'static str = env!("DIESEL_DATABASE_URL");

// connection request guard type
pub struct Connection(pub r2d2::PooledConnection<ConnectionManager<MysqlConnection>>);

pub fn connect() -> Pool {
    let manager = ConnectionManager::<MysqlConnection>::new(DATABASE_URL);
    r2d2::Pool::builder().build(manager).expect("Failed to create pool")
}

/// Attempts to retrive a single connection from managed database pool
/// If no pool is currently managed, fails with an `InternalServerError` status
/// If no connections are available, fails with a `ServiceUnavailable` status
impl<'a, 'r> FromRequest<'a, 'r> for Connection {
    type Error = ();

    fn from_request(request: &'a Request<'r>) -> request::Outcome<Connection, ()> {
        let pool = request.guard::<State<Pool>>()?;
        match pool.get() {
            Ok(conn) => Outcome::Success(Connection(conn)),
            Err(_) => Outcome::Failure((Status::ServiceUnavailable, ()))
        }
    }
}

impl Deref for Connection {
    type Target = MysqlConnection;

    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

