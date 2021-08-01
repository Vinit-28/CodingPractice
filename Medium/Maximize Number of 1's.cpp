

// Question Link :: "https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1"


// Solution //

class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        
        queue<int> zeroes;
        int start = 0, ans = INT_MIN;
        
        for(int i=0;i<n;i++)
            if( arr[i] == 0 && m == 0 )
                if( zeroes.empty()==true )
                    ans = max(abs(i-start), ans), start = i+1;
                else{
                    int index = zeroes.front();
                    zeroes.pop();
                    ans = max(abs(i-start), ans);
                    start = index+1;
                    zeroes.push(i);
                }
            else if( arr[i]==0 )
                m--, zeroes.push(i);

        ans = max(abs(start-n), ans);
        return ans;
    }  
};