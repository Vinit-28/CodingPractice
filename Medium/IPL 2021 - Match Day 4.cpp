

// Question Link :: "https://practice.geeksforgeeks.org/problems/11e021cba210768fe464423e954b3eaf7f2a7c93/1"


// Solution //

class Solution
{
    public:
    // Function for finding maximum AND value.
    int maxAND (int arr[], int n)
    {
        // Your code here
        int res = 0, onebit = 0;
        
        for(int i=31;i>=0;i--,onebit=0){
            
            for(int j=0;j<n;j++){
                
                if( (arr[j]>>i) & 1 )
                    if( (arr[j] & res) == res )
                        onebit++;
            }
            if( onebit >= 2 )
                res += (1<<i); 
        }
        return res;
    }
};