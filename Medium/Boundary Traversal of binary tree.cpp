

// Question Link :: "https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#"


// Solution //

class Solution {
public:
    Node *rootPointer;
    
    void findRightBoundary(Node *node, vector<int> &rightBoundary, bool &isRightBoundaryFound){
        
        if( isRightBoundaryFound == false && rootPointer->right!=NULL)
            rightBoundary.push_back(node->data);
        else
            return;
            
        if( node->left==NULL && node->right==NULL )
            isRightBoundaryFound = true;
        
        
        if( node->right!=NULL )
            findRightBoundary(node->right, rightBoundary, isRightBoundaryFound);

        if( node->left!=NULL )
            findRightBoundary(node->left, rightBoundary, isRightBoundaryFound);
        
    }
    
    void findLeftBoundary_LeafNodes(Node *node, vector<int> &leafNodes, vector<int> &leftBoundary, bool &isLeftBoundaryFound){
        
        if( isLeftBoundaryFound == false && rootPointer->left!=NULL)
            leftBoundary.push_back(node->data);
        
        if( node->left==NULL && node->right==NULL )
            leafNodes.push_back(node->data), isLeftBoundaryFound = true;
        
        if( node->left!=NULL )
            findLeftBoundary_LeafNodes(node->left, leafNodes, leftBoundary, isLeftBoundaryFound);
        
        if( node->right!=NULL )
            findLeftBoundary_LeafNodes(node->right, leafNodes, leftBoundary, isLeftBoundaryFound);
    }
    
    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> ans, leftBoundary, rightBoundary, leafNodes;
        bool isLeftBoundaryFound = false, isRightBoundaryFound = false;
        int i;
        
        if( root!=NULL ){
            
            rootPointer = root;
            findLeftBoundary_LeafNodes(root, leafNodes, leftBoundary, isLeftBoundaryFound);
            findRightBoundary(root, rightBoundary, isRightBoundaryFound);
    
            ans = leftBoundary;
            
            if( root->left == NULL )
                i = 0, ans.push_back(root->data);
            else
                i=1;
            
            for(; i<leafNodes.size(); i++)
                ans.push_back(leafNodes[i]);
            
            for(i=rightBoundary.size()-2; i>0; i--)
                ans.push_back(rightBoundary[i]);
        }
        return ans;
    }
};
