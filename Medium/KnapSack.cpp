#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
    int Get_Max_Value(vector<int> weights, vector<int> values, int Max_Weight_Capacity)
    {

        vector<vector<int>> dp(weights.size() + 1);
        int i, j;

        for (i = 0; i < weights.size() + 1; i++)
        {

            dp[i] = (vector<int>(Max_Weight_Capacity + 1));

            for (j = 0; j < dp[i].size(); j++)
            {

                if (i == 0)
                {

                    dp[i][j] = 0;
                }

                else if (weights[i - 1] > j)
                {

                    dp[i][j] = dp[i - 1][j];
                }

                else
                {

                    dp[i][j] = max(dp[i - 1][j], (values[i - 1] + dp[i - 1][j - weights[i - 1]]));
                }
            }
        }

        // cout<<endl;
        // for ( i=0; i<dp.size(); i++ ){

        //     for ( j=0; j< dp[i].size(); j++ ){

        //         cout<<dp[i][j]<<"\t";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;


        return dp[weights.size()][Max_Weight_Capacity];
    }
};

int main()
{

    vector<int> weights = {2, 5, 1, 3, 4}, values = {15, 14, 10, 45, 30};
    int Max_Weight_Capacity = 7;
    Solution obj;
    cout<<obj.Get_Max_Value(weights,values,Max_Weight_Capacity);
    cout << endl;
    return 0;
}