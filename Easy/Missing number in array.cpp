

// Question Link :: "https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1#"


// Solution //

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        int sum =0;
        for(int i=1;i<=n;sum+=i,i++);
        
        for(int i=0;i<n-1;i++)
            sum-=array[i];
        return sum;
    }
};