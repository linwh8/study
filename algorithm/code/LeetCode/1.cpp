class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> tables;
    for (int i = 0; i < nums.size(); i++) {
      if (tables.find(target - nums[i]) != tables.end()) {
        return {tables[target - nums[i]], i};
      } else {
        tables[nums[i]] = i;
      }
    }
  }
};
