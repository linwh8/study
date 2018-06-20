class Solution {
public:
  int countBinarySubstrings(string s) {
    int cur = -1;
    int zero_num = 0;
    int one_num = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        if (cur == 0) {
          zero_num += 1;
        } else {
          ans += min(zero_num, one_num);
          cur = 0;
          zero_num = 0;
          zero_num += 1; 
        }
      }

      if (s[i] == '1') {
        if (cur == 1) {
          one_num += 1;
        } else {
          ans += min(zero_num, one_num);
          cur = 1;
          one_num = 0;
          one_num += 1;           
        }
      }
    }

    ans += min(zero_num, one_num);

    return ans;
  }
};

