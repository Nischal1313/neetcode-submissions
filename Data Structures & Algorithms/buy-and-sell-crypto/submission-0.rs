impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        // if the vector is sorted from biggest to smallest return 0.
        let mut is_descending = true;
        for i in 0..prices.len().saturating_sub(1) {
            if prices[i] < prices[i+1] {
                is_descending = false;
                break;
            }
        }
        
        if is_descending {
            return 0;
        }

        let mut maxprofit: i32 = 0;
        let mut current_profit: i32 = 0;
        
        for i in 0..prices.len().saturating_sub(1) {
            if prices[i] < prices[i+1] {
                let mut j = i;
                let mut max_future_price = prices[i];
                while j < prices.len() {
                    if prices[j] > max_future_price {
                        max_future_price = prices[j];
                    }
                    j += 1;
                }
                current_profit = max_future_price - prices[i];
                if maxprofit < current_profit {
                    maxprofit = current_profit;
                }
            }
        }
        maxprofit
    }
}