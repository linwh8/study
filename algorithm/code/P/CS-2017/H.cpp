#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define MAX 0x3f3f3f3f
#define IN freopen("in.txt", "r", stdin);

struct Stop {
  int x;
  int y;
  int line;
  int id;

  Stop() {}
  Stop(const Stop& a) : x(a.x), y(a.y), line(a.line), id(a.id) {}
  Stop(int x, int y, int line, int id) : x(x), y(y), line(line), id(id) {}
};

bool operator!=(Stop a, Stop b) { return a.x != b.x || a.y != b.y; }

double walkingVelocity = 10;
double subwayVelocity = 40;

int lineNum = 0;
int stopNum = 0;
Stop startStop;
Stop endStop;
vector<Stop> subway;
vector<vector<double> > dist;

void buildSubway() {
  int x, y;
  while (scanf("%d %d", &x, &y) != EOF) {
    if (x == -1 || y == -1) {
      lineNum++;
      continue;
    }
    subway.push_back(Stop(x, y, lineNum, stopNum));
    stopNum++;
  }
}

void calDist() {
  dist.resize(stopNum);
  for (int i = 0; i < stopNum; i++) {
    dist[i].resize(stopNum);
    for (int j = 0; j < stopNum; j++) {
      double walkingDist = 1.0 * (sqrt(pow((subway[i].x - subway[j].x), 2) + pow(abs(subway[i].y - subway[j].y), 2))) / 1000.0;
      if (subway[i].line == subway[j].line) {
        double subwayDist = 1.0 * (abs(subway[i].x - subway[j].x) + abs(subway[i].y - subway[j].y)) / 1000.0;
        dist[i][j] = min(subwayDist / 40.0, walkingDist / 10.0);
      } else {
        dist[i][j] = walkingDist / 10.0;
      }
    }
  }
}

void dijkstra() {
  Stop cur = startStop;
  vector<int> visited(stopNum, 0);

  while (cur.id != endStop.id) {
    visited[cur.id] = 1;
    double minDist = MAX;
    int minStopId = -1;
    for (int i = 0; i < stopNum; i++) {
      if (visited[i] == 1) continue;
      if (dist[0][i] < minDist) {
        minDist = dist[0][i];
        minStopId = i;
      }
    }
    cur = subway[minStopId];
    if (cur.id == endStop.id) return;
    for (int i = 0; i < stopNum; i++) {
      dist[0][i] = min(dist[0][i], dist[0][cur.id] + dist[cur.id][i]);
    }
  }
}

int main() {
  IN
  int xStart, yStart, xEnd, yEnd;
  cin >> xStart >> yStart >> xEnd >> yEnd;
  startStop = Stop(xStart, yStart, lineNum, stopNum);
  lineNum = stopNum = 1;

  subway.push_back(startStop);
  buildSubway();
  endStop = Stop(xEnd, yEnd, lineNum+1, stopNum+1);
  subway.push_back(endStop);
  lineNum++;
  stopNum++;
  
  calDist();
  dijkstra();
  printf("%.0f\n", dist[0][stopNum-1] * 60);
  // cout << double(dist[0][stopNum-1] * 60) << endl;
}
