

// Question Link :: "https://leetcode.com/problems/implement-stack-using-queues/"


// Solution //

class MyStack {
public:
    
    queue<int> q;
    MyStack() {
       
    }
    
    void push(int x) {
        
        q.push(x);
        int size = q.size()-1;
        while( size ){
            q.push(q.front());
            q.pop();
            size-=1;
        }
    }
    
    int pop() {
        
        int ele = q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
