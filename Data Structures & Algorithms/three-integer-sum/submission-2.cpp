/* Given an integer array nums, return all the triplets [nums[i], nums[j],
nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are
all distinct.

The output should not contain any duplicate triplets. You may return the output
and the triplets in any order. */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    std::vector<vector<int>> result;
    std::sort(nums.begin(), nums.end());
    if (nums.size() < 3 || nums[0] > 0 || nums.empty())
      return result;

    for (int i = 0; i < nums.size(); ++i) {
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        if (i != nums.size()) {
          int left = i + 1;
        } else {
          left = i + 1;
        }
        if (nums[i] + nums[left] + nums[right] == 0) {
          result.push_back({nums[i], nums[left], nums[right]});
          left++;
          right--;
        } else if (nums[i] + nums[left] + nums[right] < 0) {
          left++;
        } else {
          right--;
        }
      }
    }
    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
  }
};
