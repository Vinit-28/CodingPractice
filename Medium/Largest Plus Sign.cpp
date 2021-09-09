

// Question Link :: "https://leetcode.com/problems/largest-plus-sign/"


// Solution //

class Solution {
public:


    void fillMatrix(vector<vector<int>> &grid, vector<vector<int>> &left, vector<vector<int>> &right, vector<vector<int>> &up, vector<vector<int>> &down, int n){
        
        int sum;
        // Right //
        for(int i=0;i<n;i++){

            for(int j=n-1;j>=0;j--){
                if( j==n-1 ) sum=grid[i][j];
                else if( grid[i][j]==0 ) sum = 0;
                else sum += 1;
                right[i][j]=sum;
            }
        }


        // Left //
        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){
                if( j==0 ) sum=grid[i][j];
                else if( grid[i][j]==0 ) sum = 0;
                else sum += 1;
                left[i][j]=sum;
            }
        }


        // Down //
        for(int i=0;i<n;i++){

            for(int j=n-1;j>=0;j--){
                if( j==n-1 ) sum=grid[j][i];
                else if( grid[j][i]==0 ) sum = 0;
                else sum += 1;
                down[j][i]=sum;
            }
        }

        // Up //
        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){
                if( j==0 ) sum=grid[j][i];
                else if( grid[j][i]==0 ) sum = 0;
                else sum += 1;
                up[j][i]=sum;
            }
        }
    }
    
    
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        
        vector<vector<int>> grid(n, vector<int>(n, 1)), right(n, vector<int>(n)), left(n, vector<int>(n)), up(n, vector<int>(n)), down(n, vector<int>(n));
        
        int ans=INT_MIN;
        
        for(auto v : mines) grid[v[0]][v[1]] = 0;

        fillMatrix(grid, left, right, up, down, n);

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if( grid[i][j] ){

                    int plus = min(left[i][j]-1, min(right[i][j]-1, min(down[i][j]-1, up[i][j]-1)))+1;
                    ans = max(ans, plus);
                }
            }
        }
        return (ans==INT_MIN)? 0 : ans;
    }
};
