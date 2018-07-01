#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  vector<string> v;
  string s, tmp;
  getline(cin, s);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != ' ') {
      tmp.push_back(s[i]);
    } else {
      v.push_back(tmp);
      tmp = "";
    }
  }
  v.push_back(tmp);

  for (int i = v.size() - 1; i >= 0; i--) {
    cout << v[i] << " ";
  }
}
