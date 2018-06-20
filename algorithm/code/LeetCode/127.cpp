class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    vector<int> visited;
    visited.resize(wordList.size());

    queue<pair<string, int>> q;
    q.push(pair<string, int>(beginWord, 1));

    while (!q.empty()) {
      auto word_pair = q.front();
      string word = word_pair.first;
      int count = word_pair.second;
      q.pop();
      if (word == endWord) return count;
      for (int i = 0; i < wordList.size(); i++) {
        if (visited[i] == 0 && diff(word, wordList[i]) == 1) {
          visited[i] = 1;
          q.push(pair<string, int>(wordList[i], count+1));
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
