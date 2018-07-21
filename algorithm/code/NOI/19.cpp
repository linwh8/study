#include <iostream>
#include <vector>
using namespace std;

int main() {
  int temp, s = 0, d = 0;
  int N;
  vector<vector<int> > tumor;
  cin >> N;
  tumor.resize(N + 2);
  for (int i = 0; i < N + 2; i++) {
    tumor[i].resize(N + 2);
    if (i == 0 || i == N + 1) continue;
    for (int j = 1; j < N + 1; j++) {
      cin >> temp;
      if (temp <= 50) {
        s++;
        tumor[i][j] = 1;
      }
    }
  }

  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      if (tumor[i][j] == 1) {
        if (tumor[i - 1][j] != 1 || tumor[i][j - 1] != 1 ||
            tumor[i + 1][j] != 1 || tumor[i][j + 1] != 1)
          d++;
      }
    }
  }

  cout << s << " " << d << endl;

  return 0;
}