use std::collections::HashSet;

impl Solution {
    pub fn has_duplicate(nums: Vec<i32>) -> bool {
        let mut seen = HashSet::new();
        
        for num in nums {
            // insert() returns `false` if the item was already in the set
            if !seen.insert(num) {
                return true; // We found a duplicate!
            }
        }
        
        false // If we finish the loop, everything was unique
    }
}