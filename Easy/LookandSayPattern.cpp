

//   Question Link :: "https://practice.geeksforgeeks.org/problems/decode-the-pattern1138/1"




// Solution //



class Solution
{
    public:
    string lookandsay(int n) {
        // code here
        int counter=0,i,j,k;
        string curr_patt="1",new_patt="1";
        
        for(i=1;i<n;i++){
            
            new_patt = "";
            
            int len = curr_patt.length();
            
            for(j=0;j<len;){
                
                counter = count_consecutives(curr_patt,j+1,len,curr_patt[j]) + 1;
                
                new_patt += to_string(counter) + curr_patt[j];
                
                j +=counter;
                
            }
            
            curr_patt = new_patt;
            
        }
        return new_patt;
    }   
    
    
    
    int count_consecutives(string str, int i, int l, char find){
        
        int counter=0;
        for(i;i<l;i++){
            
            if(find != str[i])
                return counter;
            counter+=1;
        }
        return counter;
    }
    
    
    
};