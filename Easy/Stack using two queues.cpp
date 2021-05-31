

//   Question Link :: "https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1"



// Solution //



//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code 
        int len1=q1.size(),len2=q2.size(),temp;
        
        if(len1==0)
            return -1;
        
        for(int i=0;i<len2;i++)
            q2.pop();
        
        for(int i=0;i<len1-1;i++){
            
            q2.push(q1.front());
            q1.pop();
        }
        
        temp = q1.front();
        q1 = q2;
        return temp;
}
