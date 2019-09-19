fn fizzbuzz(num: i32) -> String {
    let mut fb = String::new();
    match (num % 3, num % 5) {
        (0, 0) => fb.push_str("FizzBuzz"),
        (0, _) => fb.push_str("Fizz"),
        (_, 0) => fb.push_str("Buzz"),
        (_, _) => fb.push_str(&num.to_string())
    } fb
}

fn main() {
    for i in 1..=45 {
        println!("{}", fizzbuzz(i));
    }
}
