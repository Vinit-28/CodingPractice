

//   Question Link :: "https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1/?page=1&query=page1#"


// Solution //

long long int count(long long int target_sum)
{
    vector<vector<int>> dp (4);
    int i,j,arr[]={3,5,10};

    for( i =0; i < dp.size(); i++){

        dp[i] = (vector<int>(target_sum+1));

        {

            for( j=0; j<dp[i].size(); j++)
                if ( i==0 && j==0 )
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
        }
    }
    

    for ( i=1; i<dp.size(); i++){

        for ( j=0; j<dp[i].size(); j++){

            if ( arr[i-1] > j ){

                dp[i][j] = dp[i-1][j];
            }
            else{

                dp[i][j] = (dp[i-1][j]) + (dp[i][j-arr[i-1]]);
            }
        }
    }

    return dp[3][target_sum];

}