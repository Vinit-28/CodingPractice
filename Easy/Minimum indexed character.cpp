

// Question Link :: "https://practice.geeksforgeeks.org/problems/minimum-indexed-character-1587115620/1"


// Solution //

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        // Your code here
        map<char, int> hash;
        int mini = INT_MAX;
        for(int i=0;str[i];i++) hash[str[i]] = (hash[str[i]]==0)? i+1 : hash[str[i]];
        
        for(int i=0;patt[i];i++) mini = (hash[patt[i]]!=0)? min(mini, hash[patt[i]]) : mini;
        
        return (mini == INT_MAX)? -1 : mini-1;
    }
};