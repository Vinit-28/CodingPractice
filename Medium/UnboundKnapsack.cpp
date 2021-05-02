#include<iostream>
#include<vector>

using namespace std;


class Solution{

    public :

        int Get_Max_Value(vector<int> weights, vector<int> values, int Max_Weight_Capacity) {

            vector<int> dp (Max_Weight_Capacity+1);
            int i,j;

            for ( i=0; i<dp.size(); i++ ){

                dp[i] = 0;
            }

            for ( i=0; i<dp.size(); i++ ){

                for ( j=0; j<weights.size(); j++ ){

                    if ( weights[j] <= i ){

                        dp[i] =  max(dp[i], ( values[j] + dp[i-weights[j]] ));
                    }
                }
                
            }

            // cout<<endl;
            // for ( i=0; i<dp.size(); i++ ){
                
            //     cout<<dp[i]<<"\t";
            // }
            // cout<<endl;

            return dp[Max_Weight_Capacity];
        }


};

int main()
{
    
    vector<int> weights = {2, 5, 1, 3, 4}, values = {15, 14, 10, 45, 30};
    int Max_Weight_Capacity = 7;
    Solution obj;
    cout<<obj.Get_Max_Value(weights,values,Max_Weight_Capacity);
    cout<<endl;
    return 0;
}