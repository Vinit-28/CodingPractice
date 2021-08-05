

// Question Link :: "https://practice.geeksforgeeks.org/problems/flip-bits0240/1"


// Solution //

class Solution{
    public:
    int maxOnes(int arr[], int n)
    {
        // Your code goes here
        int won = 0, lost = 0;
        int f_won=0, f_lost=0;
        int totalOnes = 0;
        
        for(int i=0;i<n;i++){
            
            if( won!= 0 && won <= lost && arr[i] == 0 )
                lost = 0, won = 1;
            
            else if( arr[i]==0 )
                won+=1;

            else{
                totalOnes += 1;
                (lost == won)? (lost=won=0) : (lost+=1);
            }
            
            if( (f_won-f_lost) < (won-lost) )
                f_won = won, f_lost = lost;

        }
        
        if( f_won == 0 )
            return n;
        
        return (totalOnes + f_won)-f_lost;
    }
};