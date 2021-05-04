#include<iostream>
#include<vector>

using namespace std;


class Solution{

	public:
		int CountWays(string str){
		    
		    int  str_len = str.length();
		    vector<int> dp(str_len+1);
		    dp[0]=dp[1]=1;

		    for ( int i=1; i<str_len+1; i++ ){
		        
		        
		        if ( i==1 ){
		            
		            if ( str[i-1] == '0'){
		                
		                return 0;
		            }
		            else{
		                
		                dp[i] = 1;
		            }
		        }
		        
		        else if ( str[i-1] == '0'){
		            
    		        if (str[i-2] == '0'  ||  str[i-2] > '2'){
    		           
                        return 0;
    		        }
    		        
    		        else{
    		            
    		            dp[i] = dp[i-2];
    		        }
		        }
		        
		        else {
		            
		            if ( str[i-2] > '2' || str[i-2] == '0' || ( str[i-2] == '2' && str[i-1] > '6') ){
		                
		                dp[i]=dp[i-1];
		            }
		            
		            else{
		                
		                dp[i] = dp[i-1] + dp[i-2] ;
		            }
		        }
		        
		    }
		    
		    return dp[str_len];
		    
		}

};


int main()
{
    string encoded_string = "21123";
    Solution obj;
    
    cout<<obj.CountWays(encoded_string);
    cout<<endl;
    return 0;
}