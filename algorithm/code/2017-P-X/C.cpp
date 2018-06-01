#include <iostream>
using namespace std;

#define DEAD 1
#define ALIVE 2

int a[103][103] = {};  // all zero
int b[103][103] = {};

int main() {
  int n, m;
  

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int tmp;
      cin >> tmp;
      a[i][j] = b[i][j] = tmp + 1;  // 1 for dead and 2 for alive 
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int alive_neighbour = 0, dead_neighbour = 0;
      
      for (int ii = i - 1; ii <= i + 1; ii++) {
        for (int jj = j - 1; jj <= j + 1; jj++) {
          if (ii == i && jj == j) continue;
          if (a[ii][jj] == ALIVE) alive_neighbour++;
          else if (a[ii][jj] == DEAD) dead_neighbour++;
        }
      }

      if (a[i][j] == DEAD) {
        if (alive_neighbour == 3)
          b[i][j] = ALIVE;
      } else if (a[i][j] == ALIVE) {
        if (alive_neighbour < 2 || alive_neighbour > 3)
          b[i][j] = DEAD;
      }
    }
  }

  cout << endl;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << b[i][j]-1 << " ";
    }
    cout << endl;
  }

}

