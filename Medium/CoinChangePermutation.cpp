#include<iostream>
#include<vector>

using namespace std;


class Solution{

    public :

        int Get_Permutation_Count(vector<int> arr, int target_sum){
            
            vector<int> dp(target_sum+1);
            int i,j;
            dp[0]=1;
            for ( i=1; i<dp.size(); i++ ){

                for ( j=0; j<arr.size(); j++ ){

                    if ( arr[j] <= i ){

                        dp[i] += dp[i - arr[j]];
                    }
                }
            }
            // cout<<endl;
            // for( i=0; i<dp.size(); i++)
            //     cout<<dp[i]<<"\t";
            // cout<<endl;
            return dp[target_sum];
        }
};


int main()
{
    
    vector<int> arr = {1,2,3,4,5};
    int target_sum = 10;
    Solution obj;

    cout<<obj.Get_Permutation_Count(arr,target_sum);
    cout<<endl;
    return 0;
}