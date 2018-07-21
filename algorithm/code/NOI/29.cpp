#include <iostream>
#include <string>
using namespace std;

int main() {
  string isbn;
  cin >> isbn;
  int temp = 0;
  int count = 1;
  for (int i = 0; i < 12; i++) {
    if (isbn[i] == '-') continue;
    temp += (isbn[i] - '0') * count;
    count++;
  }
  int id = temp % 11;
  if (id == 10) {
    if (isbn[12] == 'X') {
      cout << "Right" << endl;
    } else {
      isbn[12] = 'X';
      cout << isbn << endl;
    }
  } else {
    if (id == isbn[12] - '0') {
      cout << "Right" << endl;
    } else {
      isbn[12] = id + '0';
      cout << isbn << endl;
    }
  }
}