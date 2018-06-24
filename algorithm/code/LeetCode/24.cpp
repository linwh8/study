/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    ListNode* pre = head;
    ListNode* cur = head->next;
    ListNode* ans = cur;
    while (cur->next != NULL) {
      ListNode* post = cur->next;
      ListNode* ppost = cur->next->next;
      if (ppost == NULL) {
        cur->next = pre;
        pre->next = post;
        return ans;
      } else {
        pre->next = ppost;
        cur->next = pre;
        pre = post;
        cur = ppost;  
      }
    }
    cur->next = pre;
    pre->next = NULL;
    return ans;
  }
};