#![feature(plugin)]
#![plugin(rocket_codegen)]

extern crate rocket;
extern crate rocket_contrib;
use rocket_contrib::{Json};

#[macro_use]
extern crate serde_derive;

#[derive(Deserialize)]
struct Person {
    name: String,
    age: u8
}

#[post("/hello",  data="<person>")]
fn index(person: Json<Person>) -> String {
    let Person { ref name, ref age } = *person;
    format!("Hello, {}, you are {}", name, age)
}

fn main() {
    rocket::ignite().mount("/", routes![index]).launch();
}
