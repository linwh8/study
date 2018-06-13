#define MAX 101

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    for (int i = 0; i < MAX; i++) {
      color[i] = visited[i] = 0;
      for (int j = 0; j < MAX; j++) {
        map[i][j] = 0;
      }
    }

    N = graph.size();
    for (int i = 0; i < graph.size(); i++) {
      for (int j = 0; j < graph[i].size(); j++) {
        map[i][graph[i][j]] = map[graph[i][j]][i] = 1;
      }
    }

    color[0] = 1;
    visited[0] = 1;
    for (int i = 0; i < N; i++)
      if (dfs(i) == false) return false;
    return true;
  }

  bool dfs(int from) {
    for (int to = 0; to < N; to++) {
      if (map[from][to] == 0) continue;
      if (visited[to] == 0) {
        visited[to] = 1;
        color[to] = 1 - color[from];
        if (dfs(to) == false) return false;
      } else {
        if (color[to] == color[from]) {
          return false;
        }
      }
    }
    return true;
  }

 private:
  int map[MAX][MAX];
  int color[MAX];
  int visited[MAX];
  int N;
};
