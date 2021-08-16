

// Question Link :: "https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1"


// Solution //

class Solution{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
        int zero=0, one = 0, two = 0, index=0;
        
        for(int i=0;i<n;i++)
            (a[i]==0)? (zero++) : (a[i]==1)? (one++) : (two++);
        
        for(int index=0;index<n;index++)
            (zero>0)? (a[index] = 0, zero--) : (one>0)? (a[index] = 1, one--) : (a[index] = 2, two--); 
    }
};
