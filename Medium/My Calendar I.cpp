

// Question Link :: "https://leetcode.com/problems/my-calendar-i/"


// Solution //

class Node{
    
    public:
        int start, end;
        Node *left, *right;
        Node(int start, int end){
            this->start = start, this->end = end;
            this->left = this->right = NULL;
        }
};

class MyCalendar {
public:
    Node *root;
    MyCalendar() {
        root = NULL;
    }
    
    bool book(int start, int end) {
        return bookHelper(start, end);
    }
    
    bool bookHelper(int &start, int &end){
        
        if( root == NULL ){
            root = new Node(start, end);
            return true;
        }
        Node *temp1 = root, *temp2 = NULL;
        char drctn;
        while(temp1){
            
            temp2 = temp1;
            if( isIntervalOverlapping(temp1->start, temp1->end, start, end) ) return false;
            if( start >= temp1->end ) drctn = 'r', temp1 = temp1->right;
            else drctn = 'l', temp1 = temp1->left;
            
        }
        Node *newNode = new Node(start, end);
        if( drctn == 'r' ) temp2->right = newNode;
        else temp2->left = newNode;
        return true;
    }
    
    bool isIntervalOverlapping(int &s1, int &e1, int &s2, int &e2){
        return (s1 <= s2 && s2 < e1) || (s1 < e2 && e2 <= e1) || (s2 <= s1 && s1 < e2);
    }
};
