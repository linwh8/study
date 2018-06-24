#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    backtrace(S, 0);
    return ans;
  }

  void backtrace(string str, int start) {
    if (start >= str.size()) {
      ans.push_back(str);
      return;
    }
    string temp = str;
    if (str[start] <= 'z' && str[start] >= 'a') {
      temp[start] -= 32;
    } else if (str[start] <= 'Z' && str[start] >= 'A') {
      temp[start] += 32;
    }
    backtrace(temp, start+1);
    backtrace(str, start+1);
  }

 private:
  vector<string> ans;
};

int main() {
  Solution solution;
  vector<string> v = solution.letterCasePermutation("1a2b");
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
