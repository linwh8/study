#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
  string str;
  cin >> str;
  vector<pair<char, int>> ans;
  char temp = tolower(str[0]);
  int count = 0;
  for (int i = 0; i < str.size(); i++) {
    if (tolower(str[i]) == temp) {
      count++;
    } else {
      ans.push_back(pair<char, int>(temp, count));
      temp = tolower(str[i]);
      count = 1;
    }
  }
  ans.push_back(pair<char, int>(temp, count));
  for (int i = 0; i < ans.size(); i++) {
    cout << "(" << ans[i].first << "," << ans[i].second << ")";
  }
  cout << endl;
}
