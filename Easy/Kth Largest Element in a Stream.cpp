

// Question Link :: "https://leetcode.com/problems/kth-largest-element-in-a-stream/"


// Solution //

class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int>> minHeap;
    int maxSize;
    KthLargest(int k, vector<int>& nums) {
        
        priority_queue <int> maxHeap;
        maxSize = k;
        for(int i=0;i<nums.size();i++){
            maxHeap.push(nums[i]);
        }
        
        while( k-- && maxHeap.size() ){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    int add(int val) {
        
        if( minHeap.size() == maxSize && val > minHeap.top() ){
            minHeap.pop();
            minHeap.push(val);
        }
        else if( minHeap.size() < maxSize ) minHeap.push(val);
        
        return minHeap.top();
    }
};