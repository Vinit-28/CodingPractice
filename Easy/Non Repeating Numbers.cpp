

// Question Link :: "https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1#"


// Solution //

class{
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int res=0, i, temp, a, b;
        vector<int> ans;
        for(i=0;i<nums.size();i++)
            res = (res xor nums[i]);
        
        for(i=0;i<32;i++){
            
            int bit = res>>i;
            if( bit&1 )
                break;
        }
        temp = res;
        for(int j=0;j<nums.size();j++){
            int bit = nums[j]>>i;
            
            if( bit&1 )
                res = (res xor nums[j]);
        }
        a=res, b = res xor temp;
        (a>b)? (ans = {b,a}) : (ans = {a,b}); 
        return ans;
    }
};
