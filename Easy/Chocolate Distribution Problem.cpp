

// Question Link :: "https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#"


// Solution //

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        long long int ans = LONG_LONG_MAX;
        
        sort(a.begin(), a.end());
        
        for(long int i=0; i<=(n-m);i++)
            ans = min( ans, a[(m+i)-1]-a[i] );
        
        return ans;
    }   
};