#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxHeight(vector<int>& height) {
    int N = height.size();
    if (N == 0) return 0;
    vector<int> num(N, 0);
    num[N - 1] = 1;

    for (int i = N - 2; i >= 0; i--) {
      int maxNum = 0;
      for (int j = N - 1; j > i; j--) {
        if (height[j] <= height[i] && num[j] > maxNum) {
          maxNum = num[j];
        }
      }
      num[i] = maxNum + 1;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (ans < num[i])
        ans = num[i];
    }
    return ans;
  }
};

int main() {
  int N;
  cin >> N;
  vector<int> height(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> height[i];
  }

  Solution solution;
  cout << solution.maxHeight(height) << endl;

  return 0;
}
