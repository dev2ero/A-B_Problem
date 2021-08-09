use std::io;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Reading failed");
    let num = input.trim().parse::<i32>().unwrap();

    let mut sum : i32 = 0;
    for _count in 1..=num {
        let mut input = String::new();
        io::stdin()
            .read_line(&mut input)
            .unwrap();
        let inst = input.split_whitespace();
        let mut score : i32 = 0;
        for iter in inst {
            if iter.trim().parse::<i32>().unwrap() == 1 { 
                score += 1 
            }
        }
        if score >= 2 { 
            sum += 1 
        }
    }

    println!("{}", sum);
}
