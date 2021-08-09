

// Question Link  :: "https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1#"


// Solution //

class Solution{
    public:
	    int dp[110][110];
		int row, col, lcsLen;
		vector<string> answer;
	    
	    void fillDP(string &s1, string &s2){
	        
	        for(int i=1;i<row;i++)
	            for(int j=1;j<col;j++)
	                if( s1[i-1] == s2[j-1] )
	                    dp[i][j] = 1 + dp[i-1][j-1];
	                else
	                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	    }
	    

		void searchLCS(char data[], string &s1, string &s2, int index1, int index2, int currLen){
			
			if( currLen == lcsLen ){
				data[currLen] = 0;
				answer.push_back(data);
				return ;
			}

			for(char ch='a'; ch<='z'; ch++){
				
				for(int i =index1; i<row-1; i++){

					if( ch == s1[i] ){

						for(int j = index2; j<col-1; j++){

							if( ch == s2[j] && dp[i+1][j+1] == currLen+1 ){
								data[currLen] = s1[i];
								searchLCS(data, s1, s2, i+1, j+1, currLen+1);
								goto out;
							}
						}
					}
				}
				out: {}
			}
		}

		vector<string> all_longest_common_subsequences(string s1, string s2){
		   
		    row = s1.length()+1, col = s2.length()+1;
		    answer.clear();
		    char data[row];
		    memset(dp, 0, sizeof(dp));
			fillDP(s1, s2);
			lcsLen = dp[row-1][col-1];
			searchLCS(data, s1, s2, 0, 0, 0);
		    return answer;
		}
};