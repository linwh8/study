#include <iostream>
#include <vector>
using namespace std;

long long extractMinPart(long long n) {
  for (long long i = 2; i <= n; i++) {
    if (n % i == 0) return i;
  }
  return 1;
}

int main() {
  int n;
  cin >> n;
  cout << n << "=";
  if (n == 1) {
    cout << n;
    return 0;
  }
  vector<long long> parts;
  long long part = extractMinPart(n);
  while (part != 1) {
    n /= part;
    parts.push_back(part);
    part = extractMinPart(n);
  }
  int count = 1;
  long long temp = parts[0];
  cout << parts[0];
  for (long long i = 1; i < parts.size(); i++) {
    if (parts[i] != temp) {
      if (count != 1) {
        cout << "^" << count;
        count = 1;
        temp = parts[i];
      }
      cout << "*" << parts[i];
    } else {
      count++;
    }
  }

  if (count != 1) {
    cout << "^" << count;
    count = 1;
  }
}

/*21312*/
