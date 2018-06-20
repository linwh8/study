class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> min = grid;
    int row = grid.size();
    int col = grid[0].size();

    for (int i = row - 1; i >= 0; i--) {
      for (int j = col - 1; j >= 0; j--) {
        int min_next = 9999;
        if (j + 1 < col && min[i][j + 1] < min_next) min_next = min[i][j + 1];
        if (i + 1 < row && min[i + 1][j] < min_next) min_next = min[i + 1][j];
        if (i + 1 == row && j + 1 == col) min_next = 0;
        min[i][j] = grid[i][j] + min_next;
      }
    }

    return min[0][0];
  }
};
