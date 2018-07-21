#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp (char a, char b) {
  return a < b;
}

string crack(string charset, long target) {
  vector<int> used;
  used.resize(charset.size());
  string ans;
  for (int v = 0; v < charset.size(); v++) {
    used[v] = 1;
    for (int w = 0; w < charset.size(); w++) {
      if (used[w] == 1) continue;
      used[w] = 1;
      for (int x = 0; x < charset.size(); x++) {
        if (used[x] == 1) continue;
        used[x] = 1;
        for (int y = 0; y < charset.size(); y++) {
          if (used[y] == 1) continue;
          used[y] = 1;
          for (int z = 0; z < charset.size(); z++) {
            if (used[z] == 1) continue;
            used[z] = 1;
            long temp1 = charset[v] - 'A' + 1;
            long temp2 = pow((charset[w] - 'A' + 1), 2);
            long temp3 = pow((charset[x] - 'A' + 1), 3);
            long temp4 = pow((charset[y] - 'A' + 1), 4);
            long temp5 = pow((charset[z] - 'A' + 1), 5);
            if (temp1 - temp2 + temp3 - temp4 + temp5 == target) {
              ans.resize(5);
              ans[4] = charset[z];
              ans[3] = charset[y];
              ans[2] = charset[x];
              ans[1] = charset[w];
              ans[0] = charset[v];
            }
            used[z] = 0;
          }
          used[y] = 0;
        }
        used[x] = 0;
      }
      used[w] = 0;
    }
    used[v] = 0;
  }
  return ans;
}

int main() {
  long target;
  string charset;
  while (cin >> target >> charset && target != 0) {
    sort(charset.begin(), charset.end(), cmp);
    string ans = crack(charset, target);
    if (!ans.empty())
      cout << ans << endl;
    else
      cout << "no solution" << endl;
  }
  return 0;
}
