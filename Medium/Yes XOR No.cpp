

// Question Link :: "https://practice.geeksforgeeks.org/problems/yes-xor-no2901/1#"


// Solution //

class Solution {
  public:
    string yesXorNo(int N, long long A[], long long B[]) {
        // code here[
        map<long long int, bool> hash;
        int count=0;
        
        for(int i=0;i<N;i++)
            hash[A[i]]=true, hash[B[i]]=true;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if( hash[(A[i] xor B[j])] )
                    count++;
            
                if( count%2==0 )
                    return "Yes";
            }
        }
        
        return "No";
    }
    
};
