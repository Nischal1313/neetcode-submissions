impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        if nums[0] > nums[nums.len() - 1] {
            let mut left = 0;
            let mut right = nums.len() - 1;
            while left < right {
                let mid = left + (right - left) / 2;
                if nums[mid] > nums[mid + 1] {
                    return nums[mid + 1];
                } else if nums[mid] < nums[mid - 1] {
                    return nums[mid];
                } else if nums[mid] > nums[right] {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            nums[left]
        } else {
            nums[0]
        }
    }
}
