use std::collections::HashSet;

impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut valid = true;

        let mut row_sets: Vec<HashSet<char>> = vec![HashSet::new(); 9];
        let mut col_sets: Vec<HashSet<char>> = vec![HashSet::new(); 9];
        let mut square_sets: Vec<HashSet<char>> = vec![HashSet::new(); 9];
        for i in 0..9 {
            for j in 0..9 {
                let val = board[i][j];

                if val == '.' {
                    continue;
                }

                // YOUR MATH FUNCTION: Maps 2D coordinates to a 1D square index (0 to 8)
                // i / 3 gives 0, 1, or 2. Multiplying by 3 shifts it to 0, 3, or 6.
                // j / 3 gives 0, 1, or 2. Adding them gives a unique index from 0 to 8!
                let square_idx = (i / 3) * 3 + (j / 3);

                if row_sets[i].contains(&val) {
                    valid = false;
                }
                if col_sets[j].contains(&val) {
                    valid = false;
                }
                if square_sets[square_idx].contains(&val) {
                    valid = false;
                }

                if !valid{
                    return false;
                }

                row_sets[i].insert(val);
                col_sets[j].insert(val);
                square_sets[square_idx].insert(val);
            }
        }

        true
    }
}
