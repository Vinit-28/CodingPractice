

// Question Link :: "https://practice.geeksforgeeks.org/problems/search-pattern0205/1#"


// Solution //

class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            int tlen = txt.length(), plen = pat.length();
            vector<int> ans, indexes;
            for(int i=0;i<tlen;i++)
                if( txt[i] == pat[0] )
                    indexes.push_back(i);
            
            for(auto index : indexes){
                
                bool isMatch = true;
                int i=index, j=0;
                for(; (i<tlen&&j<plen); i++,j++)
                    if( pat[j] != txt[i] ){
                        isMatch = false;
                        break;
                    }
                
                if( isMatch && j==plen )
                    ans.push_back(index+1);
            }
            return ans;
        }
};
