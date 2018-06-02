class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int num = 0;
    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[0].size(); j++)
        num += searchIsland(i, j, grid);
    return num;
  }

  int searchIsland(int i, int j, vector<vector<char>>& grid) {
    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == '1') {
      grid[i][j] = 0;
      searchIsland(i-1, j, grid);
      searchIsland(i+1, j, grid);
      searchIsland(i, j-1, grid);
      searchIsland(i, j+1, grid);
      return 1;
    }
    return 0;
  }
};
