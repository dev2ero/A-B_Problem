impl Solution {
    pub fn modify_string(s: String) -> String {
        let mut chars = s.chars().collect::<Vec<char>>();

        for i in 0..s.len() {
            let mut words = ('a'..='z').into_iter();
            if chars[i] == '?' {
                let left = if i==0 {None} else {Some(chars[i-1])};
                let right = if i==s.len()-1 {None} else {Some(chars[i+1])};
                let res = words.find( |&w| Some(w) != left && Some(w) != right);
                if let Some(w) = res { chars[i] = w };
            }
        }

        chars.into_iter().collect::<String>()
    }
}
