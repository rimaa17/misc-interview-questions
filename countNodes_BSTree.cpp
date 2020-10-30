//leetcode problem:
//https://leetcode.com/problems/count-complete-tree-nodes/
//Binary search through a binary tree in O(logn*logn)

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
    int reverseB(int mid,int h){
        bitset<32> num(mid);
        bitset<32> one(1);
        bitset<32> reversed=0;
        
        for(int i=0;i<h-1;i++)
             reversed |= ((num>>i) & one)<<(h-2-i);
       
        return (int)reversed.to_ulong();
    }
    int findH(TreeNode* root,int mid){
        if(!root) return 0;
        if(mid%2==0)
            return 1+findH(root->left,mid/2);
        if(mid%2==1)
            return 1+findH(root->right,mid/2);
        return 0; //never here   
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int h=0;
        //height
        TreeNode* it=root;
        while(it){
            it=it->left; h++;
        }
        int l=0,r=pow(2,h-1)-1,last=0;
        //binary search thro the tree
        while(l<=r){
            int mid=(l+r)/2;
            int rev_mid=reverseB(mid,h);
            if(findH(root,rev_mid)==h){
                l=mid+1;
                last=rev_mid;
                
            }
            else{
                r=mid-1;
            }
            
        }
        
        bitset<32> set(last);
        bitset<32> last_node(pow(2,h-1)-1);
        bitset<32> one(1);
        set^=last_node;
        int reversed=reverseB((int)set.to_ulong(),h);
       
        
        return pow(2,h)-1-reversed;
    }
};
