

// Question Link :: "https://practice.geeksforgeeks.org/problems/distribute-n-candies/1"


// Solution //

class Solution {
  public:
    vector<long long> distributeCandies(int N, int k) {
        // code here
        vector<long long> ans(k,0);
        int candies = 0, index=0;
        
        while(N>0){
            
            ans[index%k] += (candies+1);
            candies+=1;
            index++;
            N-=candies;
            if( candies >= N )
                candies = N-1;
        }
        
        return ans;
    }
};
