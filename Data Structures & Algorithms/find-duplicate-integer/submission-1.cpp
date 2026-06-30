#include <cmath>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     for(int num: nums){
        nums[std::abs(num)] = -1 * nums[std::abs(num)];
        if(nums[std::abs(num)] > 0) {return std::abs(num);}
     }
     return -1;
    }
    
};
