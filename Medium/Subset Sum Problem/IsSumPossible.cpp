#include<iostream>
#include<vector>


using namespace std;


class Solution 
{
    public :

        bool Is_Sum_Posiible(vector<int> arr, int target_sum){

            vector<vector<bool>>  dp(arr.size()+1);
            for( int i=0; i<dp.size(); i++){

                dp[i] = vector<bool>(target_sum+1);

                if ( i == 0){

                    for( int j=0; j<dp[0].size(); j++){

                        if ( j==0 )
                            dp[i][j] = true;
                        else
                            dp[i][j] = false;
                    }
                }

            }
            

            for( int i=1; i<dp.size(); i++){

                for (int  j = 0; j < dp[i].size(); j++){
                    
                    if ( arr[i-1] <= j){

                        if ( dp[i-1][j] || dp[i-1][j-arr[i-1]])
                            dp[i][j] = true;
                        else
                            dp[i][j] = false;

                    }
                    else{

                        dp[i][j] = dp[i-1][j];
                    }

                }
                
            }

            // for( int i=0 ; i<dp.size(); i++){
                
            //     for( int j=0 ; j<dp[i].size() ; j++)
            //         cout<<dp[i][j]<<" ";
            //     cout<<endl;
            // }

            return dp[arr.size()][target_sum];
        }
};


int main()
{
    
    vector<int> arr = {1,2,3,4,5};

    int target_sum = 7;
    Solution obj;
    cout<<obj.Is_Sum_Posiible(arr,target_sum);
    cout<<endl;
    return 0;
}