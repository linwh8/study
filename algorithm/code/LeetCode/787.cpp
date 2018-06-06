#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int K) {
    int cur_dist[101] = {};
    set<int> min_nodes, nodes;
    for (int i = 0; i < n; i++) {
      nodes.insert(i);
      cur_dist[i] = 99999;
    }

    int start = src;
    cur_dist[start] = 0;
    K++;

    while (!nodes.empty() && K != 0) {
      min_nodes.insert(start);
      nodes.erase(start);

      for (int i = 0; i < flights.size(); i++) {
        int from = flights[i][0];
        int to = flights[i][1];
        int dist = flights[i][2];

        if (from == start) { // update graph
          cur_dist[to] = min(dist + cur_dist[start], cur_dist[to]);
          if (to == dst) K--;
        }
      }

      start = *(nodes.begin());
      for (auto i = nodes.begin(); i != nodes.end(); i++) {
        if (cur_dist[start] > cur_dist[*i]) start = *i;
      }
    }

    if (cur_dist[dst] == 99999) return -1;
    else return cur_dist[dst];
  }
};

int main() {
  Solution solution;
  vector<vector<int>> flights = {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}};
  cout << solution.findCheapestPrice(4, flights, 0, 3, 1) << endl;
}
