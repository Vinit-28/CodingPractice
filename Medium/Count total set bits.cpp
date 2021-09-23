

// Question Link :: "https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1#"


// Solution //

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        if( n==0 ) return 0;
        int x=getX(n);
        return (x * (1<<(x-1))) + ((n - (1<<x) )+1) + countSetBits( (n - (1<<x) ) );
    }
    
    int getX(int n){
        
        int x=0;
        while((1<<x) <= n) x++;
        return x-1;
    }
};