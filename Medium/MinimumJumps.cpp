#include<iostream>
#include<vector>



using namespace std;


class Solution
{
    public :

    int Min_Stairs(vector<int> arr,int sum,int cur_sum)
    {
        vector<int> dp (sum+1);
        dp[sum]=0;
        int len = arr.size(),i,j;

        for(i=sum-1;i>=0;i--)
        {
            for(j=0,dp[i]=0;j<len;j++)
            {
                if(arr[j]+i <= sum)
                    if (dp[i]==0)
                        dp[i] = 1+dp[ i + arr[j] ];
                    else
                        dp[i] = min((1+dp[ i + arr[j] ]),dp[i]);
            }
        }
        // for(int i=0;i<dp.size();i++)
        //     cout<<dp[i]<<" ";
        cout<<endl;
        if(cur_sum==0)
            return dp[cur_sum];
        return dp[cur_sum]+1;

    }
};

int main()
{
    Solution obj;
    vector<int> jumps =  {8,7,5,1};
    int target_stair = 12, curr_stair = 11;
    cout<<obj.Min_Stairs(jumps,target_stair,curr_stair);
    cout<<endl;
    return 0;
}