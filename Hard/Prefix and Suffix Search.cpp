

// Question Link :: "https://leetcode.com/problems/prefix-and-suffix-search/"


// Solution //

class Trie{
    public:
        char value;
        Trie* childs[27] = {NULL};
        int indexValue;
        Trie(char ch){
            this->value = ch;
        }
};

class WordFilter {
public:
    int len;
    Trie *root;
    WordFilter(vector<string>& words) {
        
        len = words.size();
        root = new Trie('_');
        for(int i=0;i<len;i++){
            buildTrie(words[i], i);
        }
    }
    
    int f(string prefix, string suffix) {
        
        int ans;
        bool isFound = find(suffix + "#" + prefix, ans);
        if( isFound ) return ans;
        return -1;
    }
    
    
    void buildTrie(string &s, int indexValue){
        
        Trie *temp;
        string str;
        int len = s.length(), index;
        for(int i=len; i>=0; i--){
            
            if( i == len ) str = "#" + s;
            else{
                string t(1, s[i]);
                str = t + str;
            }
            temp = root;
            for(auto &ch : str){
                
                index = (ch == '#')? 26 : ch-'a';
                
                if( temp->childs[index] == NULL ){
                    Trie *newNode = new Trie(ch);
                    temp->childs[index] = newNode;
                }
                temp = temp->childs[index];
                temp->indexValue = indexValue;
            }
        }
    }
    
    bool find(string searchKey, int &ans){
        
        Trie *temp = root;
        int index;
        for(auto &ch : searchKey){
            index = ch == '#'? 26 : ch-'a';
            
            if( temp->childs[index] != NULL ){
                temp = temp->childs[index];
                ans = temp->indexValue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};