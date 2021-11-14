

// Question Link :: "https://leetcode.com/problems/iterator-for-combination/"


// Solution //

class CombinationIterator {
public:
    vector<string> patterns;
    int index, pattLen;
    string str;
    CombinationIterator(string characters, int combinationLength) {
        
        this->str = characters;
        this->pattLen = combinationLength;
        this->index = 0;
        this->patterns.clear();
        if( this->pattLen < this->str.length() ) generatePatterns(0, 0, "");
        else if( this->pattLen == this->str.length() ) patterns.push_back(this->str);
    }
    
    
    void generatePatterns(int i, int currLen, string patt){
        
        if( this->pattLen == currLen ){
            this->patterns.push_back(patt);
            return;
        }
        if( i >= this->str.length() ) return;
        generatePatterns(i+1, currLen+1, patt+this->str[i]);
        generatePatterns(i+1, currLen, patt);
    }
    
    
    string next() {
        
        if( this->hasNext() ){
            this->index+=1;
            return this->patterns[this->index-1];
        }
        return "";
    }
    
    bool hasNext() {
        return this->index < this->patterns.size();
    }
};