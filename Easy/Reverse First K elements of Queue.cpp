

// Question Link :: "https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1"


// Solution //

queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    vector<int> stack;
    queue<int> ans;
    
    if( k>q.size() )
        return q;
    
    for(int i=0;i<k;i++,q.pop())
        stack.push_back(q.front());
    
    while(stack.empty()==false){
        ans.push(stack.back());
        stack.pop_back();
    }
    
    while(q.empty()==false){
        ans.push(q.front());
        q.pop();
    }
    
    return ans;
}