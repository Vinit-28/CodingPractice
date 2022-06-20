

// Question Link :: "https://leetcode.com/problems/short-encoding-of-words/"


// Solution //

class Solution {
public:
    
    static bool comp(string &a, string &b){
        return a.size() > b.size();    
    }
    
    void makeSuffix(string &str, map<string, bool> &hash, int &len){
        
        for(int i=0;i<len;i++){
            hash[str.substr(i, len-i)] = true;    
        }
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        
        map<string, bool> hash;
        int answer = 0;
        sort(words.begin(), words.end(), comp);
        
        for(auto &word : words){
            
            if( hash[word] == false ){
                int len = word.length();
                answer += (len+1);
                makeSuffix(word, hash, len);
            }
        }
        return answer;
    }
};