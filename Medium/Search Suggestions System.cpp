

// Question Link :: "https://leetcode.com/problems/search-suggestions-system/"



// Solution //


class Trie{
    
    public:
        char value;
        bool isEnd;
        Trie *childs[26] = {NULL};
        Trie(char ch){
            this->isEnd = false;
            this->value = ch;
        }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        Trie *root = new Trie('_'), start('0');
        int ansIndex = 0;
        string searchKey = "";
        vector<vector<string>> answer;
                
        for(auto &word : products)
            insertIntoTrie(root, word);
        
        for(auto &ch : searchWord){
            
            searchKey += ch;
            answer.push_back({});
            if( contains(root, start, searchKey) ){
                int count = 0;
                DFS(answer[ansIndex], searchKey, &start, count);
            }
            ansIndex += 1;
        }
        return answer;
    }
    
    void insertIntoTrie(Trie *node, string &str){
        
        for(auto &ch : str){
            if( node->childs[ch-'a'] == NULL )
                node->childs[ch-'a'] = new Trie(ch);
            node = node->childs[ch-'a'];
        }
        node->isEnd = true;
    }
    
    bool contains(Trie *node, Trie &start, string &searchKey){
        
        for(auto &ch : searchKey){
            if( node->childs[ch-'a'] == NULL ) return false;
            node = node->childs[ch-'a'];
            start = *(node);
        }
        return true;
    }
    
    void DFS(vector<string> &ans, string str, Trie *node, int &count){
        
        if( node->isEnd ){
            ans.push_back(str);
            count+=1;
        }
        for(int i=0;i<26;i++){
            
            if( count >= 3 ) return;
            if( node->childs[i] != NULL ){
                string temp(1, i+'a');
                DFS(ans, str + temp, node->childs[i], count);
            }
        }
    }
};