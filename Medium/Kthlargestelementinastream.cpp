

//   Question Link :: "https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1"



// Solution //



class Solution{
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        
        priority_queue<int, vector<int>, greater<int>> heap;
        
        int i,j;
        
        vector<int> ans;
        
        for(i=0;i<n;i++){
            
            if(i<k){
                heap.push(arr[i]);
            }
            else if(arr[i] > heap.top() ){
                heap.pop();
                heap.push(arr[i]);
            }
            
            if(i+1 >= k){
                ans.push_back(heap.top());
            }
            else{
                ans.push_back(-1);
            }
        
        }
        
        return ans;
        
    }
};