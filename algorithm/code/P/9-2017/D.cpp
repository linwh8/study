#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool isPrime(long x) {
  if (x == 1) return false;
  for (long i = 3; i <= sqrt(x); i += 2) {
    if (x % i == 0) return false;
  }
  return true;
}

bool isRecursive(long x) {
  string str;
  stringstream ss;
  ss << x;
  ss >> str;
  if (str[0] == '5' || (str[0] - '0') % 2 == 0) return false;
  for (int i = 0; i < str.size() / 2; i++) {
    if (str[i] != str[str.size() - 1 - i]) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "2 3 5 7" << endl;
    return 0;
  }
  if (n % 2 == 0 && n != 2) return 0;

  vector<long> ans;
  for (long i = pow(10, n - 1) + 1; i < pow(10, n) - 1; i += 2) {
    if (isRecursive(i)) {
      if (isPrime(i)) {
        ans.push_back(i);
      }
    }
  }

  if (ans.size() == 0) return 0;
  cout << ans[0];
  for (int i = 1; i < ans.size(); i++) {
    cout << " " << ans[i];
  }
  cout << endl;
}