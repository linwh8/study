class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    row = grid.size();
    col = grid[0].size();

    int max_area = 0;
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        max_area = max(max_area, searchIsland(i, j, grid));

    return max_area;
  }

  int searchIsland(int i, int j, vector<vector<int>> &grid) {
    if (i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == 1) {
      grid[i][j] = 0;
      return 1 + searchIsland(i+1, j, grid) + searchIsland(i-1, j, grid) + searchIsland(i, j-1, grid) + searchIsland(i, j+1, grid);
    }
    return 0;
  }

private:
  int row, col;
};
