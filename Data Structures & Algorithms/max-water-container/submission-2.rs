impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = height.len() - 1;
        let mut max_water = 0;
        
        while left < right {
            // Calculate the width between the two pointers
            let width = (right - left) as i32;
            
            // The height is limited by the shorter wall
            let current_height = height[left].min(height[right]);
            
            // Calculate the area
            let current_area = width * current_height;
            
            // Update max area if current is larger
            if current_area > max_water {
                max_water = current_area;
            }
            
            // Move the pointer with the shorter height
            // This is the key optimization - we move the smaller wall
            if height[left] < height[right] {
                left += 1;
            } else {
                right -= 1;
            }
        }
        
        max_water
    }
}