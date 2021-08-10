use std::io;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .unwrap();
    let mut list = input.split_whitespace();
    let (m, n) : (i32, i32) = (list.next().unwrap().parse().unwrap(), list.next().unwrap().parse().unwrap());
    println!("{}", m*n/2);
}
