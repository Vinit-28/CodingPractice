

// Question Link :: "https://leetcode.com/problems/stream-of-characters/"


// Solution //

class Node{
    public:
        char letter;
        Node *childs[26];
        bool isWordEnd = false; 
        Node(char letter){
            this->letter = letter;
            for(int i=0;i<26;i++) childs[i] = NULL;
        }
};

class StreamChecker {
public:
    vector<string> words;
    string stream;
    Node *root = new Node('0');
    
    StreamChecker(vector<string>& words) {
        this->words = words, this->stream="";
        root= new Node('0');
        root->letter='0';
        for(auto s:words)
            insert(s);
    }
    
    bool query(char letter) {
        
        Node *node = root;
        stream += letter;
        char c;
        for(int i=stream.length()-1;i>=0;i--){
            c=stream[i];
            
            if( node->childs[c-97] == NULL || node->isWordEnd) break;
            else node = node->childs[c-97];
            
        }
        return node->isWordEnd; 
    }
    
    
    void insert(string &s){
        Node *node = root;
        char c;
        for(int i=s.length()-1;i>=0;i--){
            c = s[i];
            if( node->childs[c-97] == NULL ){
                Node *newNode = new Node(c);
                node->childs[c-97] = newNode;
            }
            node = node->childs[c-97];
        }
        node->isWordEnd = true;
    }
};
