#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int count = 0;
    if (find(wordList.begin(), wordList.end(), beginWord) != wordList.end()) count += 1;

    vector<int> visited;
    visited.resize(wordList.size());

    queue<string> q;
    q.push(beginWord);

    while (!q.empty()) {
      string word = q.front();
      q.pop();
      if (word == endWord) return count - 1;
      count += 1;
      for (int i = 0; i < wordList.size(); i++) {
        if (visited[i] == 0 && diff(word, wordList[i]) == 1) {
          visited[i] = 1;
          q.push(wordList[i]);
        }
      }
    }

    return 0;
  }

private:
  int diff(string a, string b) {
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) count += 1;
    }
    return count;
  }
};


int main() {
  string beginWord = "hot";
  string endWord = "dog";
  vector<string> wordList = {"hot","dot","dog"};

  Solution solution;
  cout << solution.ladderLength(beginWord, endWord, wordList) << endl;
}
