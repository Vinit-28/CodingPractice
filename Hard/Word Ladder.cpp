

// Question Link :: "https://leetcode.com/problems/word-ladder/"


// Solution //

class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        map<string, bool> wordsAvailable, isVisited;
        string q[wordList.size()+1];
        int front=0, last=0, pathLen = 1;
        
        for(auto &s : wordList) wordsAvailable[s]=true;
        
        if( !wordsAvailable[endWord] ) return 0; // If endWord is not present in wordList //
        
        q[last] = beginWord, last++;
        
        while(front<last){
            
            
            int len = (last-front);
            
            while(len>0){
                
                auto word = q[front];
                front++;
                
                for(int i=0;i<word.length();i++){
                    string temp = word;
                    
                    for(auto ch='a'; ch<='z';ch++){
                        temp[i] = ch;
                        if( word[i] != ch && wordsAvailable[temp] && !isVisited[temp] ){
                            isVisited[temp]= true, q[last]=temp, last++;
                            if( temp == endWord ) return pathLen+1;
                        }
                    }
                }
                
                len--;
            }
            
            pathLen++;
        }
        
        return 0;
    }
};