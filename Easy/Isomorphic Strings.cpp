

// Question Link :: "https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1"


// Solution //

#include<map>

class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    
    bool areIsomorphic(string str1, string str2)
    {
        // Your code here
        if( str1.length() != str2.length() )
            return false;
            
        map<char, char> util;
        
        for(int i=0;i<str1.length();i++){
            
            if( !util[str1[i]] ){
                
                for(auto p : util)
                    if( p.second == str2[i] )
                        return false;
                util[str1[i]] = str2[i];
            }
            
            else
                if( util[str1[i]] != str2[i] )
                    return false;
        }
        return true;
    }
};
