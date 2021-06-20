

// Question Link :: "https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1#"


// Solution //

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       priority_queue<int, vector<int>, greater<int>> heap;
       rec(root1,heap);
       rec(root2,heap);
       
       vector<int> ans;
       
       while( ! heap.empty()){
           
           ans.push_back(heap.top());
           heap.pop();
       }
       
       return ans;
    }
    
    void rec(Node *node, priority_queue<int, vector<int>, greater<int>> &heap){
        
        heap.push(node->data);
        if( node->left != NULL)
            rec(node->left,heap);
            
        if( node->right != NULL)
            rec(node->right,heap);
            
    }
};
