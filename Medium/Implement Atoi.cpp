

// Question Link :: "https://practice.geeksforgeeks.org/problems/implement-atoi/1"


// Solution //

class Solution{
    public:
        /*You are required to complete this method */
    int atoi(string str)
    {
        //Your code here
        int ans = 0, isnegative=0;
        for(int i=0;i<str.length();i++){
            
            if( i == 0 && str[i] == '-' )
                isnegative = 1;
            
            else if( str[i] < '0' || str[i] > '9' )
                return -1;
            
            else
                ans = (ans*10)+(int(str[i])-48);
        }
        (isnegative)? (ans-=(ans*2)) : (ans);
        return ans;
    }
};