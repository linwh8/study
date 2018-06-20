#include <string>
#include <iostream>
using namespace std;

#define MAX 1001

class Solution {
public:
  int countSubstrings(string s) {
    int ans = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        visited[i][j] = false;

    // len = 1
    for (int i = 0; i < n; i++) {
      ans++;
      visited[i][i] = true;
    }

    // len = 2
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i+1]) {
        ans++;
        visited[i][i+1] = true;
      }
    }

    // len >= 3
    for (int len = 3; len < n+1; len++) {
      for (int i = 0; i < n-len+1; i++) {
        int j = i + len - 1;  // last char
        if (visited[i+1][j-1] == true && s[i] == s[j]) {
          visited[i][j] = true;
          ans++;
        }
      } 
    }
  
  }

private:
  bool visited[MAX][MAX];
  string str;
};

int main() {
  Solution solution;
  cout << solution.countSubstrings("abc") << endl;
}
