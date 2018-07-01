#include <iostream>
#include <vector>
using namespace std;


class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    vector<vector<int>> augmentGrid;
    int row = grid.size();
    int col = grid[0].size();
    augmentGrid.resize(row+2);
    for (int i = 0; i < augmentGrid.size(); i++) {
      augmentGrid[i].resize(col+2);
      if (i != 0 && i != row+1) {
        for (int j = 0; j < col; j++) {
          augmentGrid[i][j+1] = grid[i-1][j];
        }
      }
    }
    int ans = 0;
    for (int i = 1; i < row+2; i++) {
      for (int j = 1; j < col+2; j++) {
        if (augmentGrid[i][j] == 1) {
          if (augmentGrid[i+1][j] == 0) {
            ans++;
            // augmentGrid[i+1][j] = -1;
          }
          if (augmentGrid[i-1][j] == 0) {
            ans++;
            // augmentGrid[i-1][j] = -1;
          }
          if (augmentGrid[i][j-1] == 0) {
            ans++;
            // augmentGrid[i][j-1] = -1;
          }
          if (augmentGrid[i][j+1] == 0) {
            ans++;
            // augmentGrid[i][j+1] = -1;
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> test = {{0,1}};
  cout << solution.islandPerimeter(test) << endl;
}
