

// Question Link :: "https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#"


// Solution //

class Solution{
    public:
    
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i=0;i<r+1;i++)
            heap.push(arr[i]);
        
        for(int i=0;i<k-1;i++)
            heap.pop();
            
        return heap.top();
    }
};