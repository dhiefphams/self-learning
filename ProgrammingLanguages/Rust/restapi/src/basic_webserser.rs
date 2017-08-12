/**
 * Basic web server in Rust
 */

use std::io::{Read, Write, BufReader, BufRead};
use std::net::{TcpListener, TcpStream};

fn main() {
    // create connection in a port and
    // gets it ready to accept connection
    let listener = TcpListener::bind("localhost:8081").unwrap();

    // this listener's accept method waits or blocks until
    // we have a connection and then return  a new tcpstream
    // that we can read and write data to.
    let stream = listener.accept().unwrap().0;
    handle_request(stream);
}

// this function takes the stream we just got from the
// listener and then reads some data from it
fn handle_request(stream: TcpStream) {
    let mut reader = BufReader::new(stream);
    for line in reader.by_ref().lines() {
        if line.unwrap() == "" {
            break;
        }
    }

    send_resp(reader.into_inner());
}


// Response the http request
fn send_resp(mut stream: TcpStream) {
    let response = "HTTP/1.1 200 OK\n\n<html><body>Hello World</body></html>";
    stream.write_all(response.as_bytes()).unwrap();
}