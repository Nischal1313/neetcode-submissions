impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let mut return_vec = vec![0; nums.len()];

        let mut product: i32 = 1;
        let mut zero_count = 0;

        for &num in &nums {
            if num != 0 {
                product *= num;
            } else {
                zero_count += 1;
            }
        }

        for i in 0..nums.len() {
            if nums[i] != 0 {
                if zero_count == 0 {
                    return_vec[i] = product / nums[i];
                } else {
                    return_vec[i] = 0;
                }
            } else {
                if zero_count > 1 {
                    return_vec[i] = 0;
                } else {
                    return_vec[i] = product;
                }
            }
        }

        return_vec
    }
}
