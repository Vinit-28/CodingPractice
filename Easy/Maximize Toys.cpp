

// Question Link :: "https://practice.geeksforgeeks.org/problems/maximize-toys0331/1"


// Solution //

class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        // code here
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<arr.size();i++,ans++){
            
            if(K<arr[i])
                return ans;
            K -= arr[i];
        }
        
        return ans;
    }
};
