

// Question Link :: "https://practice.geeksforgeeks.org/problems/maximum-and-value-1587115620/1"


// Solution //

class Solution
{
    public:
    // Function for finding maximum AND value.
    int maxAND (int arr[], int n)
    {
        // Your code here
        int ans=0, onebit=0;
        
        for(int i=31;i>=0;i--,onebit=0){
            
            for(int j=0;j<n;j++)
                if( (arr[j]>>i) & 1 )
                    if( (ans & arr[j]) == ans )
                        onebit += 1;
            
            if( onebit>=2 )
                ans += 1<<i;
        }
        return ans;
    }
};
