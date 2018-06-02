/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  bool findTarget(TreeNode* root, int k) {
    if (root == NULL) return false;
    
    vector<int> nums;
    inOrder(root, nums);

    for (int i = 0; i < nums.size(); i++) {
      for (int j = i+1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == k) return true;
      }
    }

    return false;
  }

private:
  void inOrder(TreeNode* root, vector<int> nums) {
    if (root == NULL) return;
    inOrder(root->left, nums);
    nums.push_back(root->val);
    inOrder(root->right, nums);
  }
};