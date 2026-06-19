use std::collections::HashMap;

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        // make a hash map. (Key = the number, Value = its frequency)
        let mut hash_map: HashMap<i32, i32> = HashMap::new();
                
        for i in nums {
            if hash_map.contains_key(&i) {
                
                *hash_map.get_mut(&i).unwrap() += 1;
            } else {
                
                hash_map.insert(i, 1);
            }
        }
                
        let mut pairs: Vec<(i32, i32)> = hash_map.into_iter().collect();
        
        
        pairs.sort_by(|a, b| b.1.cmp(&a.1));
        
        
        pairs.into_iter()
            .take(k as usize)
            .map(|(num, _freq)| num)
            .collect()
    }
}