#include<iostream>
#include<vector>

using namespace std;


class Solution{

    public :

        vector<vector<int>> Get_Possible_Subsets( vector<int> arr, int target_sum ){

            vector<vector<int>> dp (arr.size()+1), Possible_subsets;
            vector<vector<string>> dp_str (arr.size()+1);
            vector<string> vec;
            int i,j;
            string temp;

            for ( i =0 ;i < dp.size(); i++ ){

                dp[i] = (vector<int>(target_sum+1));
                dp_str[i] = (vector<string>(target_sum+1));

                if ( i==0 ){

                    for ( j = 0; j< dp[i].size(); j++ ){

                        if ( j==0 )
                            dp[i][j] = 1, dp_str[i][j] = "0";
                        else
                            dp[i][j] = 0,dp_str[i][j] = "";
                    }
                }
            }



            for ( i=1; i< dp.size(); i++ ){

                for ( j=0; j< dp[i].size(); j++ ){

                    if ( arr[i-1] > j ){

                        dp[i][j] = dp[i-1][j];
                        dp_str[i][j] = dp_str[i-1][j];
                    }

                    else{

                        dp[i][j] = ( dp[i-1][j] + dp[i-1][j-arr[i-1]]);
                        if ( dp_str[i-1][j-arr[i-1]] != "" ){
                         
                            temp = "";
                            vec = Split_String(dp_str[i-1][j-arr[i-1]],'\\');

                            for ( int k=0; k<vec.size(); k++ )
                                temp += (vec[k] + "," + to_string(arr[i-1])) + "\\";
                            // dp_str[i][j] = dp_str[i-1][j] + "\\" + dp_str[i-1][j-arr[i-1]] + "," + to_string(arr[i-1]);

                            dp_str[i][j] = dp_str[i-1][j] + "\\" + temp;
                        }
                        else
                            dp_str[i][j] = "";
                    }
                }
            }


            Possible_subsets = Convert_String_to_Subsets(dp_str[arr.size()][target_sum]);

            return Possible_subsets;
        }


        vector<vector<int>> Convert_String_to_Subsets(string str){

            vector<string> splitted_str = Split_String(str,'\\');
            vector<string> numbers;
            
            vector<vector<int>> Subsets;
            vector<int> set;

            for ( int i=0;i<splitted_str.size();i++){

                numbers = Split_String(splitted_str[i],',');
                set = {};
                for ( int j=0; j<numbers.size(); j++){
                    
                    if ( numbers[j] != "0")
                        set.push_back(to_int(numbers[j]));

                }

                Subsets.push_back(set);

            }

            return (Subsets);
        }


        int to_int(string str){

            int num=0;
            for ( int i=0; i<str.length(); i++){

                num = (num*10) + (int(str[i])-48);
            }
            return num;
        }


        vector<string> Split_String(string str, char splitter){

            vector<string> splitted_string;
            string temp="";
            for( int i=0; i<str.length(); i++){

                if ( splitter == str[i]){

                    if ( temp.length()){

                        splitted_string.push_back(temp);
                    }
                    temp="";
                }
                else{
                    
                    temp += str[i];
                }

            }

            if ( temp.length() )
                splitted_string.push_back(temp);
            return splitted_string;
        
        }

};


int main()
{

    vector<int> arr={1,2,3,5,6,8};
    vector<vector<int>> Subsets;
    int target_sum = 11;
    Solution obj;
    
    Subsets = obj.Get_Possible_Subsets(arr,target_sum);

    // Printing of Subsets //
    for ( int i=0; i<Subsets.size(); i++){
        
        cout<<"\n[ ";
        for ( int j=0; j<Subsets[i].size(); j++){

            cout<<Subsets[i][j]<<", ";
        }
        cout<<"\b\b ]\n";
    }
    
    cout<<endl;
    return 0;
}