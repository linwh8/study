#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
 public:
  string simplifyPath(string path) {
    stack<string> folders;
    string dots;
    string foldername;
    for (int i = 0; i < path.size(); i++) {
      if (path[i] == '.') {
        dots += ".";
      } else if (path[i] == '/') {
        
      } else {
        if (dots.size() == 3) {
          continue;
        } else if (dots.size() == 2) {
          folders.pop();
        }
        dots.clear();
      }
    }

    string ans;
    while (!chars.empty()) {
      ans = chars.top() + ans;
      chars.pop();
    }

    if (ans[ans.size() - 1] == '/' && ans.size() > 1) ans = ans.substr(0, ans.size() - 1);

    return ans;
  }
};

int main() {
  Solution solution;
  cout << solution.simplifyPath("/abc/...") << endl;
}
