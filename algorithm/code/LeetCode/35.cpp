#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    if (target > nums[nums.size()-1]) return nums.size();
    if (target < nums[0]) return 0;

    nums = nums;
    int start = 0, end = nums.size() - 1;

    while (start < end) {
      int mid = (start + end) / 2;
      if (target < nums[mid]) {
        end = mid;
      } else if (target == nums[mid]) {
        return mid;
      } else {
        start = mid + 1;
      }
    }

    if (nums[start] == target) return start;
    else return end;
  }

 private:
  vector<int> nums;
};

int main() {
  Solution s;
  vector<int> v = {1, 3, 5, 6};
  cout << s.searchInsert(v, 7) << endl;
}
