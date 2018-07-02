#include <iostream>
using namespace std;

bool isPrime(int x) {
  if (x == 1) return false;
  for (int i = 3; i*i <= x; i+=2) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int X, Y;
  int ans = 0;
  cin >> X >> Y;
  if (X > Y) {
    int temp = X;
    X = Y;
    Y = temp;
  }
  if (X <= 2) {
    X = 3;
    ans = 1;
  }
  for (int i = X; i <= Y; i++) {
    if (i % 2 == 0) continue;
    if (isPrime(i)) ans++;
  }
  cout << ans << endl;
}
