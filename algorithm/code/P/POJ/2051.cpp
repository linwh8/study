#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

class cmp {
 public:
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
      return a.first > b.first;
    } else {
      return a.second > b.second;
    }
  }
};

int main() {
  string junk;
  priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
  map<int, int> query_period;
  int temp1, temp2;
  while (cin >> junk && junk != "#") {
    cin >> temp1 >> temp2;
    pq.push(pair<int, int>(temp1, temp2));
    query_period[temp1] = temp2;
  }
  int K;
  cin >> K;
  while (K--) {
    int id = pq.top().first;
    int period = pq.top().second;
    cout << pq.top().first << endl;
    pq.pop();
    pq.push(pair<int, int>(id, period + query_period[id]));
  }

  return 0;
}