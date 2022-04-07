

// Question Link :: "https://leetcode.com/problems/last-stone-weight/"



// Solution //

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> heap;
        int size = stones.size();
        
        for(auto &n : stones) heap.push(n);
        
        while(size){
            
            if( size == 1 ) return heap.top();
            else{
                
                int y = heap.top();
                heap.pop();
                int x = heap.top();
                heap.pop();
                size -= 2;
                
                if( x != y ) heap.push(y-x), size+=1; 
            }
        }
        return 0;
    }
};