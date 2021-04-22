

//  Question Link :: "https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1"


// Solution //

class Solution
{
    public:
    vector<string> res;
    vector<string> AllParenthesis(int n) 
    {
        rec(0,0,n,"");
        return res;
    }
    
    void rec(int open,int close,int n,string comb)
    {
        if(open<n)
            rec(open+1,close,n,comb+"(");
        
        if(close<open)
        {
            rec(open,close+1,n,comb+")");
        }
        
        if(open==n&&close==n)
        res.push_back(comb);
    }
};
