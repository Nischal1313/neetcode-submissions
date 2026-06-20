impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        if nums.len() == 0 {
            return 0;
        }
        let set: std::collections::HashSet<i32> = nums.into_iter().collect();
        let mut longest_consecutive_sequence: i32 = 0;
        for &num in &set {
            if !set.contains(&(num - 1)) {
                let mut current_longest: i32 = 1;
                let mut current = num;
                while set.contains(&(current + 1)) {
                    current_longest += 1;
                    current += 1;
                }
                if current_longest > longest_consecutive_sequence {
                    longest_consecutive_sequence = current_longest;
                }
            }
        }
        longest_consecutive_sequence
    }
}