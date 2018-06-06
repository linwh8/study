#define MAX 9999

class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> min = triangle; 
    for (int i = triangle.size() - 2; i >= 0 ; i--) {
      for (int j = 0; j < triangle[i].size(); j++) {
        int min_next = MAX;
        for (int k = j; k <= j+1; k++) {
          if (min[i+1][k] < min_next)
            min_next = min[i+1][k];
        }
        min[i][j] = triangle[i][j] + min_next;
      }
    }

    return min[0][0];
  }
};
