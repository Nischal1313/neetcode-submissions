impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let n = height.len();
        let mut new_vec: Vec<i32> = Vec::new();

        for i in 0..n {
            let max_left = height[..i].iter().cloned().max().unwrap_or(0);
            let max_right = height[i+1..].iter().cloned().max().unwrap_or(0);
            let water = max_left.min(max_right) - height[i];
            new_vec.push(0.max(water));
        }

        new_vec.iter().sum()
    }
}