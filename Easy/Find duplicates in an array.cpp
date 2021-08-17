

// Question Link :: "https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1"


// Solution //

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int> ans;
        for(int i=0;i<n;i++){
            
            int index = arr[i]%n;
            arr[index] += n;
        }
        
        for(int i=0;i<n;i++)
            if( (arr[i]/n) > 1 )
                ans.push_back(i);
        
        if( ans.empty() )
            return {-1};
        
        return ans;
    }
};