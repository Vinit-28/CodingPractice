#include<iostream>
#include<vector>

using namespace std;


class Solution{


    public :

        int Get_Count_of_Possible_Ways( vector<int> arr, int target_sum ){

            
            vector<vector<int>> dp (arr.size()+1);
            int i,j;

            for ( i =0 ;i < dp.size(); i++ ){

                dp[i] = (vector<int>(target_sum+1));

                if ( i==0 ){

                    for ( j = 0; j< dp[i].size(); j++ ){

                        if ( j==0 )
                            dp[i][j] = 1;
                        else
                            dp[i][j] = 0;
                    }
                }
            }



            for ( i=1; i< dp.size(); i++ ){

                for ( j=0; j< dp[i].size(); j++ ){

                    if ( arr[i-1] > j ){

                        dp[i][j] = dp[i-1][j];
                    }

                    else{

                        dp[i][j] = ( dp[i-1][j] + dp[i-1][j-arr[i-1]]);
                    }
                }
            }

            // cout<<endl;
            // for ( i=0; i< dp.size(); i++ ){

            //     for ( j=0; j< dp[i].size(); j++)
            //         cout<<dp[i][j]<<"\t";
            //     cout<<endl;
            // }
            // cout<<endl;

            return dp[arr.size()][target_sum];
        }

};


int main()
{
    vector<int> arr={1,2,3,5,6,8};
    int target_sum = 11;
    Solution obj;
    cout<<obj.Get_Count_of_Possible_Ways(arr,target_sum);
    cout<<endl;
    return 0;
}