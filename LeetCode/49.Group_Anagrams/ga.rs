impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut d: std::collections::HashMap<String, Vec<String>> = std::collections::HashMap::new();
        for word in &strs {
            let mut w = word.as_bytes().to_vec();
            w.sort();
            d.entry(String::from_utf8(w).unwrap()).or_default().push(word.to_owned());
        }
        d.values().cloned().collect()
    }
}
