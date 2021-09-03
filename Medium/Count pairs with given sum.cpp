

// Question Link :: "https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1"


// Solution //

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        map<int, int> hash;
        int ans=0;
        for(int i=0;i<n;i++){
            if(hash[k-arr[i]] > 0)
                ans+= hash[k-arr[i]];
            hash[arr[i]] += 1;
        }
        return ans;
    }
};