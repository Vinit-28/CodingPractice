

// Question Link :: "https://practice.geeksforgeeks.org/problems/diagonal-morning-assembly0028/1"


// Solution //

class Solution{
  public:
    void diagonalSort(vector<vector<int> >& matrix, int n, int m) {
        // code here 
        
        // For Upper Right Triangle //
        for(int i=1;i<m;i++){
            
            priority_queue<int> heap;
            
            for(int r=0,c=i;(r<n&&c<m); r++,c++)
                heap.push(matrix[r][c]);
            
            for(int r=0,c=i;!heap.empty();heap.pop(),r++,c++)
                matrix[r][c] = heap.top();
        } 
        
        
        // For Lower Left Triangle //
        for(int i=1;i<n;i++){
            
            priority_queue<int, vector<int>, greater<int>> heap;
            
            for(int r=i,c=0;(r<n&&c<m); r++,c++)
                heap.push(matrix[r][c]);
            
            for(int r=i,c=0;!heap.empty();heap.pop(),r++,c++)
                matrix[r][c] = heap.top();
        } 
      
    }
};
