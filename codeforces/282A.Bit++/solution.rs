use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let num : i32 = input.trim().parse().unwrap();
    let mut x : i32 = 0;
    for _ in 1..=num {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        if input.find('+') != None {
            x += 1;
        } else {
            x -= 1;
        }
    }

    println!("{}", x);
}
