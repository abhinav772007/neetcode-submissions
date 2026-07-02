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
    // bool find(TreeNode* root,TreeNode* tar,vector<TreeNode*> &pat){
    //     if(root==nullptr)return false;
    //     pat.push_back(root);
    //     if(tar==root)return true;
    //     if(find(root->left,tar,pat)|| find(root->right,tar,pat))return true;
    //     pat.pop_back();
    //     return false;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<TreeNode*> par1,par2;
        // find(root,p,par1);
        // find(root,q,par2);
        // TreeNode* ans=nullptr;
        // int i=0;
        // while(i<par1.size() && i<par2.size() && par1[i]==par2[i]){
        //     ans=par1[i];
        //     i++;
        // }
        // return ans;
    TreeNode* cur=root;
        while(cur!=nullptr){
            if(cur->val > p->val && cur->val > q->val)cur=cur->left;
            else if(cur->val<p->val && cur->val < q->val)cur=cur->right;
            else return cur;
        }

    }
};
