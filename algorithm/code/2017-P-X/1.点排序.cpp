#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> startpoint;

bool mysort(pair<int, int> a, pair<int, int> b) {
  int dista = abs(a.first - startpoint.first) + abs(a.second - startpoint.second);
  int distb = abs(b.first - startpoint.first) + abs(b.second - startpoint.second);
  if (dista == distb) {
    if (a.first == b.first) {
      return a.second < b.second;
    } else {
      return a.first < b.first;
    } 
  } else {
    return dista < distb;
  }
}

int main() {
  int n;
  vector<pair<int, int>> points;
  
  cin >> startpoint.first >> startpoint.second;
  cin >> n;
  points.resize(n);
  for (int i = 0; i < n; i++)
    cin >> points[i].first >> points[i].second;
  
  sort(points.begin(), points.end(), mysort);

  for (int i = 0; i < n; i++) {
    cout << "(" << points[i].first << ", " << points[i].second << ") ";
  }
}
