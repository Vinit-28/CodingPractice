#include<iostream>
#include<vector>


using namespace std;

class Solution 
{
    public :

        int GetMaxGold(vector<vector<int>> Maze, int row, int col, int curr_i, int curr_j)
        {
            vector<vector<int>> dp ;
            int i,j;

            for(i=0;i<row;i++)
                dp.push_back(vector<int>(col));

            
            for( j = col-1; j>=0; j-- ){

                for( i = row-1; i>=0; i-- ){

                    if ( j == col-1 ){
                        dp[i][j] = Maze[i][j];
                    }

                    else{
                        
                        if ( i == row-1 ){
                            dp[i][j] = ( Maze[i][j] + ( max(dp[i][j+1], dp[i-1][j+1]) ));
                        }

                        else if ( i == 0 ){
                            dp[i][j] = ( Maze[i][j] + ( max(dp[i][j+1], dp[i+1][j+1]) ));
                        }
                        
                        else{
                            dp[i][j] = ( Maze[i][j] + max(dp[i-1][j+1], ( max(dp[i][j+1], dp[i+1][j+1]) )));
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

            
            return dp[curr_i][curr_j];
        }
};


int main()
{
    
    vector<vector<int>> Maze = {{0,1,4,2,8,2},
                                {4,3,6,5,0,4},
                                {1,2,4,1,4,6},
                                {2,0,7,3,2,2},
                                {3,1,5,9,2,4},
                                {2,7,0,8,5,1}};
    
    int row = 6, col = 6, curr_i = 3, curr_j = 0;
    Solution obj;
    cout<<obj.GetMaxGold(Maze,row,col,curr_i,curr_j);
    cout<<endl;
    return 0;
}