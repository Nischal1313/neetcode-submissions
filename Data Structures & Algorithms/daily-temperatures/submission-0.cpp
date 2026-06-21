#include <vector>
#include <stack>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> result(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            if (st.empty() || temperatures[st.top()] >= temperatures[i]) {
                st.push(i);
            } else {
                while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                    result[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};