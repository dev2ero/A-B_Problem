impl Solution {
    pub fn monotone_increasing_digits(n: i32) -> i32 {
        let (mut base, mut result) = (111111111, 0);
        for _ in 0..9 {
            while result + base > n {
                base /= 10;
            }
            result += base;
        }
        result
    }
}
