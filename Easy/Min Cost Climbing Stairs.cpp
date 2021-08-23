

// Question Link :: "https://practice.geeksforgeeks.org/problems/min-cost-climbing-stairs/1"


// Solution //

class Solution {
  public:
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        //Write your code here
        int min1=cost[N-2], min2=cost[N-1];
        for(int i=N-3;i>=0;i--){
            int temp = cost[i] + min(min1, min2);
            min2 = min1, min1 = temp;
        }
        return min(min1, min2);
    }
};