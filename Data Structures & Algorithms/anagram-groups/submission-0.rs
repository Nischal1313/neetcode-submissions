use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut anagram_map: HashMap<String, Vec<String>> = HashMap::new();        
        for s in strs {
            let mut chars: Vec<char> = s.chars().collect();
            chars.sort_unstable();
            let sorted_key: String = chars.into_iter().collect();
            
            anagram_map.entry(sorted_key).or_default().push(s);
        }
        anagram_map.into_values().collect()
    }
}