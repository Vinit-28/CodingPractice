

// Question Link :: "https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1"


// Solution //

void BFS(Node *node, vector<int> &ans){
    
    queue<Node*> nodes;
    map<Node*, int> levels;
    vector<int> stack;
    
    nodes.push(node), levels[node] = 0;
    int currLvl = 0;
    char dir = 'r';
    
    while(nodes.empty() == false){
        
        auto n = nodes.front();
        nodes.pop();
     
        if( levels[n] > currLvl ){
            currLvl = levels[n];
        
            if( dir == 'r' )
                for(int i=stack.size()-1; i>=0; i--)
                    ans.push_back(stack[i]);
            else
                for(int i=0; i<stack.size(); i++)
                    ans.push_back(stack[i]);
            
            dir = (dir=='r')? 's' : 'r';
            stack.clear();
        }
        
        stack.push_back(n->data);
        
        if( n->left!=NULL ){
            nodes.push(n->left), levels[n->left] = levels[n], levels[n->left]++;
        }
        
        if( n->right!=NULL )
            nodes.push(n->right), levels[n->right] = levels[n]+1;
    }
    
    if( dir == 'r' )
        for(int i=stack.size()-1; i>=0; i--)
            ans.push_back(stack[i]);
    else
        for(int i=0; i<stack.size(); i++)
            ans.push_back(stack[i]);
}

vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if( root!=NULL )
        BFS(root, ans);
    return ans;
}
