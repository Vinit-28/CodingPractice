

// Question Link :: "https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1"


// Solution //

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      map<int, bool> hash;
      int start=-1, ans=1, count=0;
      for(int i=0;i<N;i++) hash[arr[i]] = true;
      
      for(auto p : hash){
          
        if(start==-1)
            start=p.first, count=1;
        
        else
            if( start==(p.first-1) )
                start++, count++;
            else
                start=p.first, count=1;
        
        ans = max(ans, count);
      }
      
      return ans;
    }
};
