#include <vector>
#include <algorithm>
using namespace std;


class Solution {
 public:
  int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int ans = 0, shorter = -1;

    while (left != right) {
      int dist = right - left;

      if (height[left] > height[right]) {
        shorter = right;
        right--;
      } else {
        shorter = left;
        left++;
      }
      
      if (dist * height[shorter] > ans) ans = dist * height[shorter];
    }

    return ans;
  }
};
