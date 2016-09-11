#include <iostream>
#include <vector>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
	
class Solution {
	vector<TreeNode*> nodeList;
	TreeNode* root;
	bool flag;
	bool compare;
	int index;
public:

	Solution() {
		flag = false;
		compare = false;
	}

    bool isSymmetric(TreeNode* root) {
        this->root = root;
        return inOrder(root);
    }
    
    
    bool inOrder(TreeNode* root) {
		
		if (root == NULL)
			return false;
		
		inOrder(root->left);
		
		if (this->root == root) {
			compare = true;
			index = nodeList.size() - 1;
			inOrder(root->right);
			return;
		}
		
		if (compare) {
			TreeNode *v1 = root;
			TreeNode *v2 = nodeList[index--];
	
			if ((v1 == NULL && v2 == NULL) || (v1 != NULL && v1->val == v2->val)) {
			} else {
				return false;
			}
		} else {
			nodeList.push_back(root);
		}
	
		inOrder(root->right);
	}
	
	void printNodeList() {
		for (unsigned i = 0; i < nodeList.size(); i++) {
			cout<<nodeList[i]->val<<" ";
		}
	}
	
    
    
};

int main() {
	vector<int> first;
	
	TreeNode *root = new TreeNode(1);
	
	TreeNode *left = new TreeNode(2);
	TreeNode *right = new TreeNode(2);
	
	TreeNode *left1 = new TreeNode(3);
	TreeNode *right1 = new TreeNode(3);
	
	
	root->left = left;
	root->right = right;

	left->left = left1;
	right->right = right1;

	Solution s;
	s.isSymmetric(root);
	return 0;
	
}

