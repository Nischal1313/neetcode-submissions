use std::collections::HashSet;
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut sub_string_count: HashSet<char> = HashSet::new();
        let mut final_count = 0;
        let mut left = 0;
        let chars: Vec<char> = s.chars().collect();

        for right in 0..chars.len() {
            while sub_string_count.contains(&chars[right]) {
                sub_string_count.remove(&chars[left]);
                left += 1;
            }
            sub_string_count.insert(chars[right]);
            let streak = (right - left + 1) as i32;
            if streak > final_count {
                final_count = streak;
            }
        }
        final_count
    }
}