/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<int>res;
	int helper(TreeNode* root, int d) {
		if (!root) {
			return 0;
		}
		queue<TreeNode*>q;
		q.push(root);
		q.push(NULL);
		res.push_back(d);
		while (!q.empty()) {
			TreeNode* tmp = q.front();
			q.pop();
			if (tmp != NULL) {
				if (tmp->left) {
					q.push(tmp->left);
				}
				if (tmp->right) {
					q.push(tmp->right);
				}
			}
			else {
				if (!q.empty()) {
					q.push(NULL);
					d++;
					res.push_back(d);
				}
			}
		}
		return *max_element(res.begin(), res.end());
	}
	int maxDepth(TreeNode* root) {
		int d = 1;
		return helper(root, d);
	}
};