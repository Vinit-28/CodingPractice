

// Question Link :: "https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1"


// Solution //

class Solution{
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    int minDeg, maxDeg;

    void BFS(Node *root, map<int, vector<int>> &verticalOrderUtils){
        
        queue<pair<Node*, int>> q;
        q.push({root,0});
        
        while(q.empty()==false){
            
            auto p = q.front();
            q.pop();
            
            verticalOrderUtils[p.second].push_back(p.first->data);
            
            if( p.first->left!=NULL )
                q.push({p.first->left,p.second+1});
            
            if( p.first->right!=NULL )
                q.push({p.first->right,p.second-1});
            
            minDeg = min(minDeg, p.second);
            maxDeg = max(maxDeg, p.second);
        }
    }
    
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        minDeg=INT_MAX, maxDeg = INT_MIN;
        map<int, vector<int>> verticalOrderUtils;
        BFS(root, verticalOrderUtils);
        vector<int> verticalOrder;
      
        while(maxDeg >= minDeg){
            
            for(auto n : verticalOrderUtils[maxDeg])
                verticalOrder.push_back(n);
            maxDeg-=1;
        }
        return verticalOrder;
    }
};
