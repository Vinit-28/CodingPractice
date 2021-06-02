


// This is a Practice Question and I have taken the reference of Pepcoding to find this question //
// Question Cum Solution video link -> "https://youtu.be/kh48JLieeW8" 




// Solution //


#include<iostream>

using namespace std;


class Solution{

    public:

        int minCost(int n, int red[], int green[], int blue[]){

            int dp[n][n], o_r_e, o_r_i;
            char r_e_c;
            
            for(int i=0; i<n; i++){

                if(i==0){

                    dp[0][i] = red[i];
                    if( green[i] <= blue[i] ){
                        
                        r_e_c = 'G';
                        dp[1][i] = green[i];
                    }
                    else{

                        r_e_c = 'B';
                        dp[1][i] = blue[i];
                    }
                }

                else{

                    dp[0][i] = red[i] + dp[1][i-1];

                    if(dp[0][i-1] <= dp[1][i-1]){

                        dp[1][i] = dp[0][i-1];
                        
                        if(green[i] <= blue[i]){

                            r_e_c = 'G';
                            dp[1][i] += green[i];
                        }
                        else{

                            r_e_c = 'B';
                            dp[1][i] += blue[i];
                        }

                    }
                    else{

                        dp[1][i] = dp[1][i-1];
                        
                        if(r_e_c == 'G'){
                            dp[1][i] += blue[i];
                            r_e_c = 'B';
                        }
                        else{
                            dp[1][i] += green[i];
                            r_e_c = 'G';
                        }
                    }

                }
            }

            // cout<<endl;
            // for(int i=0;i<2;i++){
            //     for(int j=0;j<n;j++){
            //         cout<<dp[i][j]<<"\t";
            //     }
            //     cout<<endl;
            // }

            return min(dp[0][n-1],dp[1][n-1]);
            
        }

};


int main()
{
    
    int n=4, red[] = {1,5,3,1}, green[] = {5,8,2,2}, blue[] = {7,4,9,4};
    Solution object;
    cout<<"Minimum cost -> "<<object.minCost(n,red,green,blue);
    cout<<endl;
    return 0;
}