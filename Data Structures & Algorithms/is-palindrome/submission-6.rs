impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let cleaned: Vec<char> = s.chars()
            .filter(|c| c.is_alphanumeric())
            .map(|c| c.to_ascii_lowercase())
            .collect();

        cleaned == cleaned.iter().rev().cloned().collect::<Vec<char>>()
    }
}