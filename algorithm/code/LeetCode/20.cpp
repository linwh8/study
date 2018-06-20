#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> brackets;

    for (int i = 0; i < s.size(); i++) {
      if (brackets.empty()) {
        brackets.push(s[i]);
      } else if (s[i] == ')' && brackets.top() == '(') {
        brackets.pop();
      } else if (s[i] == '}' && brackets.top() == '{') {
        brackets.pop();
      } else if (s[i] == ']' && brackets.top() == '[') {
        brackets.pop();
      } else {
        brackets.push(s[i]);
      }
    }

    return brackets.empty();
  }
};
