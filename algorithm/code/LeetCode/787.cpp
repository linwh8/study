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
    vector<vector<int>> cur_dist(n, vector<int>(n, 99999));
    vector<int> nodes(n, -1);  // -1 for find routes

    int start = src;
    cur_dist[start][0] = 0;

    while (!nodes.empty()) {
      nodes[start] = 1;
      int max_dist = 0;
      int min_node = -1;

      for (int i = 0; i < flights.size(); i++) {
        int from = flights[i][0];
        int to = flights[i][1];
        int dist = flights[i][2];

        if (from == start) {  // update graph
          for (int i = 0; i < n; i++) {
            cur_dist[to][i+1] = min(dist + cur_dist[start][i], cur_dist[to][i+1]);
            if (max_dist < cur_dist[to][i+1]) {
              min_node = to;
              max_dist = cur_dist[to][i+1];
            }
          }
        }
      }

      start = min_node;
    }

    int ans;
    for (int i = 0; i < K; i++) {
      if (cur_dist[dst][i] < ans)
        ans = cur_dist[dst][i];
    }

    return ans;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> flights = {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}};
  cout << solution.findCheapestPrice(4, flights, 0, 3, 1) << endl;
}
