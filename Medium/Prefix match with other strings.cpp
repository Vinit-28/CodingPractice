

//   Question Link :: "https://practice.geeksforgeeks.org/problems/prefix-match-with-other-strings/1"



// Solution //


class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        
        string pre = get_pre(str,k);
        int count=0,i;
        for(i=0;i<n;i++){
            
            if(pre==get_pre(arr[i],k))
                count+=1;
            
        }
        return count;
    }
    
    
    string get_pre(string s, int k){
        string pre="";
        for(int i=0;i<k;i++){
            pre+=s[i];
        }
        return pre;
    }
};