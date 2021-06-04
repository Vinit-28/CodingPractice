

//   Question Link :: "https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#"



// Solution //

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        if(n==1)
            return {1};
        
        vector<long long int> ans,first = getfirst(nums,n),second=getsecond(nums,n);
        
        for(int i=0;i<n;i++){
            
            if(i==0){
                ans.push_back(second[i+1]);
            }
            else if(i==n-1){
                ans.push_back(first[i-1]);
            }
            else{
                ans.push_back( ( first[i-1] * second[i+1] ) );
            }
            
        }
        
        return ans;
        
    }
    
    vector<long long int> getfirst(vector<long long int> nums, int n){
        
        vector<long long int> p;
        
        for(int i=0;i<n;i++){
            
            if(i==0)
                p.push_back(nums[i]);
            else
                p.push_back(nums[i] * p[i-1]);
            
        }
        return p;
    }
    
    vector<long long int> getsecond(vector<long long int> nums, int n){
        
        vector<long long int> p(n);
        
        for(int i=n-1;i>=0;i--){
            
            if(i==n-1)
                p[i] = nums[i];
            else
                p[i] = nums[i]*p[i+1];
            
        }
        return p;
    }
};