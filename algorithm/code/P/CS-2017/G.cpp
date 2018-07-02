#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, std::greater<int> > pq;
    while (n--) {
      int type;
      cin >> type;
      if (type == 1) {
        int u;
        cin >> u;
        pq.push(u);
      } else {
        cout << pq.top() << endl;
        pq.pop();
      }
    }
  }
}
