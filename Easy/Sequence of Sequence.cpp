

// Question Link :: "https://practice.geeksforgeeks.org/problems/sequence-of-sequence1155/1"


// Solution //

class Solution{
public:
    int count;
    int numberSequence(int m, int n){
        // code here
        count=0;
        
        for(int i=1;(i<=m);i++)
            rec(n, i, m, 1);
        return count;
    }
    
    void rec( int &n, int num, int &m, int index ){
        
        if( index == n ){
            count++;
            return;
        }
        int newNum = num*2;
        for(int i=0;(newNum+i <= m); i++)
            rec(n, newNum+i, m, index+1 );
    }
    
};