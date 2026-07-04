#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

      stack<pair<int, int>> fifo_stack; 
        int max_area = 0;
        int n = heights.size();
        
        for (int i = 0; i < n; ++i) {
            int start = i;
            
            while (!fifo_stack.empty() && fifo_stack.top().second > heights[i]) {
                int height = fifo_stack.top().second;
                start = fifo_stack.top().first;
                fifo_stack.pop();
                max_area = max(max_area, height * (i - start));
            }
            
            fifo_stack.push({start, heights[i]});
        }
        
        
        while (!fifo_stack.empty()) {
            int height = fifo_stack.top().second;
            int start = fifo_stack.top().first;
            fifo_stack.pop();
            max_area = max(max_area, height * (n - start));
        }
        
        return max_area;
    }
};