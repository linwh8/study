#include <iostream>
#include <vector>
using namespace std;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int extractMinPart(int n) {
  for (int i = 0; i < primes.size(); i++) {
    if (n % primes[i] == 0) return primes[i];
  }
  return 1;
}

int main() {
  int n;
  cin >> n;
  vector<int> parts;
  int part = extractMinPart(n);
  while (part != 1) {
    n /= part;
    parts.push_back(part);
    part = extractMinPart(n);
  }
  int count = 1;
  int temp = parts[0];
  cout << parts[0];
  for (int i = 1; i < parts.size(); i++) {
    if (parts[i] != temp) {
      if (count != 1) {
        cout << "^" << count;
        count = 1;
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
  
  cout << endl;
}
