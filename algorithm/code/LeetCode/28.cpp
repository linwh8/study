#include <cmath>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle == "") return 0;
    if (haystack.size() < needle.size()) return -1;
    if (haystack.size() == needle.size()) return haystack == needle ? 0 : -1;
    vector<int> pmt = calculate_partial_table(needle);
    for (int i = 0; i < haystack.size();) {
      int k = 0;
      while (needle[k] == haystack[i+k]) {
        if (k == needle.size() - 1) {
          return i;
        } else {
          k++;
        }
      }
      if (k != 0)
        i += (k - pmt[k-1]);
      else
        i++;
    }
    return -1;
  }

  vector<int> calculate_partial_table(string& needle) {
    vector<int> ans;
    string temp;
    for (int i = 0; i < needle.size(); i++) {
      temp += needle[i];
      ans.push_back(calculate_partial(temp));
    }
    return ans;
  }

  int calculate_partial(string& str) {
    string prefix, postfix;
    int ans = 0;
    for (int i = 0; i < str.size() - 1; i++) {
      prefix += str[i];
      postfix = str[str.size() - i - 1] + postfix;
      if (prefix == postfix) {
        ans = i+1;
      }
    }
    return ans;
  }
};

