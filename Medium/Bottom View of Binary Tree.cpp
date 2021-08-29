

// Question Link :: "https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#"


// Solution //

class Solution {
  public:
  
  
    void BFS(Node *root, map<int, Node*> &hash){
        
        queue<pair<int, Node*>> q;
        q.push({0, root});
        
        while(q.empty()==false){
            
            auto node = q.front();
            q.pop();
            
            hash[node.first] = node.second;
            
            if( node.second->left!=NULL )
                q.push({node.first-1, node.second->left});
            
            if( node.second->right!=NULL )
                q.push({node.first+1, node.second->right});
        }
    }
  
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int, Node*> hash;
        vector<int> answer;
        
        if( root!=NULL ){
            
            BFS(root, hash);
            for(auto p : hash)
                answer.push_back(p.second->data);
        }
        return answer;
    }
};