extern crate csv;
#[macro_use]
extern crate serde_derive;


fn simple_writer() {
    let dollar_films = vec![
        ("A firstful of Dollars", "Rojo", 1964),
        ("Inception", "Nolan", 2010),
        ("The God Father", "Mario PUzo", 1974),
        ];
    let path = "western.csv";
    let mut writer = csv::WriterBuilder::new().from_path(path).unwrap();
    for row in dollar_films {
        writer.serialize(row).expect("CSV writer error");
    }
    writer.flush().expect("Failed to write to disk");
}

#[derive(Serialize)]
struct StockPrice<'a> {
    name: &'a str,
    open: f32,
    high: f32,
    close: f32,
    low: f32
}


fn with_seralize() {
    let mut writer = csv::WriterBuilder::new().from_writer(vec![]);
    let data = vec![
        StockPrice {
            name: "DHG",
            open: 22.2f32,
            high: 25.4f32,
            low: 21.1f32,
            close: 23.2f32,
        },
        StockPrice {
            name: "VCB",
            open: 100.0f32,
            high: 100.0f32,
            low: 22.0f32,
            close: 55.1f32,
        }
    ];
    for record in data {
        writer.serialize(record).expect("Can write");
    }

    println!("{}", String::from_utf8(writer.into_inner().expect("err")).expect("err"))

}

fn main() {
   // simple_writer();
   with_seralize();
}

