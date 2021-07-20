

// Question Link :: "https://practice.geeksforgeeks.org/problems/longest-consecutive-1s-1587115620/1"


// Solution //

class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        // code here
        bitset<32> bin(N);
        int count=0, ans=0;
        for(int i=0;i<32;i++){
            
            if( bin[i]==0 )
                count=0;
            else
                count++;
            
            ans = max(ans, count);
        }
        return ans;
    }
};
