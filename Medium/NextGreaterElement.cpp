


//  Question Link :: "https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#"



// Solution //



class Solution{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Your code here
        vector<long long> res(n),vec;
        int len=0,j,i;
        res[n-1]=-1;
        for(i=n-1;i>0;i--)
        {
            if(arr[i]>arr[i-1])
            {
                vec.push_back(arr[i]);
                len++;
            }
            else
            {
                
                while(len>0 && vec[len-1]<=arr[i-1])
                {
                    vec.pop_back();
                    len--;
                }
                if(len==0)
                {
                    vec.push_back(-1);
                    len++;
                }
            }
            res[i-1]=vec[len-1];
        }
        // reverse(res.begin(),res.end());
        return res;
    }
};

