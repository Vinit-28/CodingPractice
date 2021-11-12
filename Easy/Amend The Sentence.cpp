

// Question Link :: "https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1"


// Solution //

class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string ans = "", temp="";
        int wordCount = 0;
        for(int i=0; s[i]; i++)
            if( s[i] >= 'A' && s[i] <= 'Z' && i!=0 ){
                if( wordCount == 0 ) ans = temp;
                else ans += (" " + temp);
                temp = "", wordCount++, temp += s[i];
            }
            else temp += s[i];
        
        if( temp != "" )
            if( wordCount == 0 ) ans = temp;
            else ans += (" " + temp);
            
        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
        return ans;
    }
};