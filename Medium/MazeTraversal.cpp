#include<iostream>
#include<vector>


using namespace std;

class Solution 
{
    public :

        int GetMinCost(vector<vector<int>> Maze, int row, int col, int curr_i, int curr_j)
        {
            vector<vector<int>> dp ;
            int i,j;

            for(i=0;i<row;i++)
                dp.push_back(vector<int>(col));

            for( i = row-1; i>=0; i-- ){

                for( j = col-1; j>=0; j-- ){

                    if (i == row-1 && j == col-1 ){
                        dp[i][j] = Maze[i][j];
                    }

                    else if ( j == col-1 ){
                        dp[i][j] = Maze[i][j] + dp[i+1][j];
                    }
                    
                    else if ( i == row-1 ){
                        dp[i][j] = Maze[i][j] + dp[i][j+1];
                    }
                    
                    else{

                        if ( dp[i][j+1] < dp[i+1][j]){
                            dp[i][j] = Maze[i][j] + dp[i][j+1];
                        }
                        else{
                            dp[i][j] = Maze[i][j] + dp[i+1][j];
                        }
                    }
                }
            }

            // for( i =0; i<row; i++ ){
            //     for( j=0; j<col; j++ ){
            //         cout<<dp[i][j]<<"\t";
            //     }
            //     cout<<endl;
            // }

            if ( curr_i == row-1 && curr_j == col-1 ){
                return 0;
            }
            return dp[curr_i][curr_j];
        }
};


int main()
{
    
    vector<vector<int>> Maze = {{1,1,5,10,3},
                                {4,6,11,9,5},
                                {5,1,5,7,1},
                                {7,11,1,2,5},
                                {9,10,1,1,3}};
    
    int row = 5, col = 5, curr_i = 0, curr_j = 0;
    Solution obj;
    cout<<obj.GetMinCost(Maze,row,col,curr_i,curr_j);
    cout<<endl;
    return 0;
}