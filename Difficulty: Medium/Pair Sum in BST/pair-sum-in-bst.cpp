/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  void inorder(Node*root,vector<int>& arr){
      if(root == NULL)
      return;
      
      inorder(root->left,arr);
      arr.push_back(root->data);
      inorder(root->right,arr);
  }
    bool findTarget(Node *root, int target) {
       vector<int>arr;
       
       inorder(root,arr);
       int left = 0;
       int right = arr.size()-1;
       
       while(left < right){
           int sum = arr[left]+arr[right];
           
           if(sum==target)
           return true;
           
           if(sum < target)
           left++;
           else 
           right--;
       }
       return false;
    }
};