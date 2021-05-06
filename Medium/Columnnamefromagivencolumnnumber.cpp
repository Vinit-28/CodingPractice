


//  Question Link :: "https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1"



// Solution //


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string Alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",ans="";
        
        if ( n < 26 ){
            
            ans += Alpha[n-1];
        }
        
        else {
            
            vector<int> vec;
            long long int temp=n;
            int l=0;
            
            while(true){
                
                vec.push_back(temp%26);
                l++;
                
                if ( l>1 ){
                    
                    if ( vec[l-2] == 0){
                        
                        vec[l-1] -=1;
                    }
                }
                
                if ((temp/26) < 26){
                    
                    vec.push_back(temp/26);
                    l++;
                    
                    if ( l>1 ){
                    
                        if ( vec[l-2] == 0){
                            
                            vec[l-1] -=1;
                        }
                    }
                    
                    break;
                    
                }
                temp/=26;
            }
            
            for(int i=l-1;i>=0;i--){
                
                if ( vec[i] == 0 ){
                    
                    ans += Alpha[25];
                }
                
                else{
                    
                    ans += Alpha[vec[i]-1];
                }
            }
            
        }
        return ans;
    }
};
