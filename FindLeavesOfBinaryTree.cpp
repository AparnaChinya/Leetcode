/*
366. Find Leaves of Binary Tree
Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
 
Example:
Input: [1,2,3,4,5]
 
          1
         / \
        2   3
       / \
      4   5
Output: [[4,5,3],[2],[1]]
 
Explanation:
1. Removing the leaves [4,5,3] would result in this tree:
          1
         /
        2
 
2. Now removing the leaf [2] would result in this tree:
          1
 
3. Now removing the leaf [1] would result in the empty tree:
          []

From <https://leetcode.com/problems/find-leaves-of-binary-tree/description/>
*/
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
    int findLeavesHelper(TreeNode *root, vector<vector<int>> &result) {
        if(root == NULL) {
            return -1;
        }

        int left = findLeavesHelper(root->left,result);
        int right = findLeavesHelper(root->right,result);

        //Calculate the depth and add the nodes to each level of the tree
        int level = 1 + max(left,right);

        //Remember to add empty entry to vector of vectors
        if(result.size() < level + 1) {
            result.push_back(vector<int>());
        }
        result[level].push_back(root->val);
        return level;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        findLeavesHelper(root,result);
        return result;
    }
};

