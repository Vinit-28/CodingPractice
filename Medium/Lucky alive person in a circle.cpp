

// Question Link :: "https://practice.geeksforgeeks.org/problems/lucky-alive-person-in-a-circle1229/1#"


// Solution //

class Solution{
public:
    int find(int N){
        // code here
        int num, temp=0;
        
        for(int i=0; (temp<N); i++)
            num = temp, temp = 1<<i;
        
        return 2*(N-num)+1;
    }
};
