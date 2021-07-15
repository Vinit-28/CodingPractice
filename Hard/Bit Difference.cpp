

// Question Link :: "https://practice.geeksforgeeks.org/problems/find-sum-of-different-corresponding-bits-for-all-pairs4652/1"


// Solution //

class Solution{
public:

    int countBits(int n, long long int arr[])
    {
        // code here
        long long int sum = 0;
        long long int i,j,counter;
        auto mod = 1000000007;
        for(i=31;i>=0;i--){
            
            for(j=0, counter = 0; j<n; j++){
                
                int bit = arr[j]>>i;
                (bit&1)? (counter++) : (counter);
            }
            sum = (sum%mod) + ( ( ( ( (counter%mod) * ( (n-counter)%mod ) )%mod) *2)%mod);
        }
        return (sum%mod);
    }
};
