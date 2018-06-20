class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int slow = 0, fast = 0;
    int ans = 0;
    int len = s.size();
    while (slow < len) {  // use < instead of != to avoid empty string
      int temp = 0;
      int visited[256] = {};  // not only a-z, but also '/" etc.
      while (fast < len && visited[s[fast]] != 1) {  // boundary
        visited[s[fast]] = 1;
        fast++;
        temp++;
      }
      if (temp > ans) ans = temp;
      slow++;
      fast = slow;
    }
    return ans;
  }
};
