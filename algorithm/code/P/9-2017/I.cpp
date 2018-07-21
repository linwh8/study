#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> expenses;

int getMax(int s, int e) {
  int max = 0;
  int maxId = -1;
  for (int i = s; i < e; i++) {
    if (expenses[i] > max) {
      max = expenses[i];
      maxId = i;
    }
  }
  return maxId;
}

int main() {
  cin >> N >> M;
  expenses.resize(N);
  for (int i = 0; i < N; i++) cin >> expenses[i];

  int maxId = getMax(0, expenses.size());
  int temp = 0;
  for (int i = 0; i < maxId; i++) {
    if (temp + expenses[i] <= expenses[maxId]) {
      temp += expenses[i];
    } else {
      temp = 0;
    }
  }
}
