impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let m = matrix.len();
        let n = matrix[0].len();

        let mut top = 0;
        let mut bottom = m;

        while top < bottom {
            let mid_row = top + (bottom - top) / 2;
            if matrix[mid_row][0] <= target && target <= matrix[mid_row][n - 1] {
                let mut left = 0;
                let mut right = n;
                while left < right {
                    let mid_col = left + (right - left) / 2;
                    if matrix[mid_row][mid_col] == target {
                        return true;
                    } else if matrix[mid_row][mid_col] < target {
                        left = mid_col + 1;
                    } else {
                        right = mid_col;
                    }
                }
                return false;
            } else if target < matrix[mid_row][0] {
                bottom = mid_row;
            } else {
                top = mid_row + 1;
            }
        }
        false
    }
}