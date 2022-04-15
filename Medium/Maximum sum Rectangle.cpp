

// Question Link :: "https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#"


// Solution //

class Solution {
  public:
  
    void doPrefixSum(int &R, int j, vector<vector<int>> &mat, vector<vector<int>> &helper){
        
        int sum = 0;
        for(int i=0;i<R;i++){
            sum += mat[i][j];
            helper[i][j] = sum;
        }
    }
    
    
    int findNextColSum(int &C, int curCol, int r1, int r2, vector<vector<int>> &helper, int &maxSum){
        
        if( curCol >= C ) return 0;
        
        int sum = (r1==0)? helper[r2][curCol] : (helper[r2][curCol] - helper[r1-1][curCol]);
        
        maxSum = max(maxSum, sum);
        
        int temp = findNextColSum(C, curCol+1, r1, r2, helper, maxSum);
        if( (temp+sum) > sum ) sum += temp, maxSum = max(maxSum, sum);
        
        return sum;
    }
  
  
    int maximumSumRectangle(int R, int C, vector<vector<int>> mat) {
        // code here
        
        int maxSum = INT_MIN;
        vector<vector<int>> helper(R, vector<int>(C, 0));
        
        for(int j=0;j<C;j++){
            doPrefixSum(R, j, mat, helper);
        }
        
        for(int i=0;i<R;i++){
            
            for(int j=i;j<R;j++){
                
                maxSum = max(maxSum, findNextColSum(C, 0, i, j, helper, maxSum));
            }
        }
        
        return maxSum;
    }
};