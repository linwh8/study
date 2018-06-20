#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<int> dp(nums.size(), 0);
    vector<int> pre(nums.size(), 0);
    int biggestNum = 0, k = 0;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = i; j >= 0; j--) {
        if (nums[i] % nums[j] == 0) {
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            pre[i] = j;
          }
          if (dp[i] > biggestNum) {
            biggestNum = dp[i];
            k = i;
          }
        }
      }
    }

    vector<int> ans;
    for (int i = 0; i < biggestNum; i++) {
      ans.push_back(nums[k]);
      k = pre[k];
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
