#include <iostream>
#include <string>
using namespace std;

// v - w2 + x3 - y4 + z5 = target 

string crack(string charset, long target) {
  
}


int main() {
  long target;
  string charset;
  while (cin >> target >> charset && target != 0) {
    string ans = crack(charset, target);
    if (!ans.empty()) cout << ans << endl;
    else cout << "no solution" << endl;
  }
  return 0;
}
