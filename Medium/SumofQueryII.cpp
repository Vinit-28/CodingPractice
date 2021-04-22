

//  Question Link :: "https://practice.geeksforgeeks.org/problems/sum-of-query-ii5310/1"



// Solution //

class Solution{
public:
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int> res;
        int l,r,sum=0;
        for(int i=0;i<(2*q);i+=2)
        {
            l=queries[i],r=queries[i+1],sum=0;
            for(int j=l-1;j<r;j++)
            {
                sum+=arr[j];
            }
            res.push_back(sum);
        }
        return res;
    }
};
