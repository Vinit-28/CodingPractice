

//   Question Link :: "https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1"



// Solution //


class Solution {
  public:
  
    vector<vector<string>> ans;
    int str_len;
    string ques_str;
    
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        
        str_len = s.length();
        ques_str = s;
        ans={};
        rec({},0);
        return ans;
    }
    
    
    void rec(vector<string> pair, int index){
        
        if(index == str_len){
            
            ans.push_back(pair);
            return;
        }
        
        string temp="";
        for(index;index<str_len;index++){
            
            temp += ques_str[index];
            
            if(is_palin(temp)){
                
                pair.push_back(temp);
                
                rec(pair,index+1);
                
                pair.pop_back();
            }
        }
        
        
    }
    
    
    bool is_palin(string s){
        
        int i=0,j=s.length()-1,m=(j+1)/2;
        
        while (i<=m){
            if(s[i]!=s[j])
                return false;
        
            i+=1;
            j-=1;
        }
        return true;
    }
};