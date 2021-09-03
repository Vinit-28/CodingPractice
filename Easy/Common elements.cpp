

// Question Link :: "https://practice.geeksforgeeks.org/problems/common-elements1132/1#"


// Solution //

class Solution
{
    public: 
    
        int getmini(int &i, int &j, int &k, int A[], int B[], int C[], int &n1, int &n2, int &n3 ){
            
            int mini = INT_MAX;
            if( i<n1 )
                mini = min(A[i], mini);
            
            if( j<n2 )
                mini = min(B[j], mini);
            
            if( k<n3 )
                mini = min(C[k], mini);
            
            return mini;
        }
        
        vector<int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
            
            vector<int> ans;
            for(int i=0,j=0,k=0; (i<n1 || j<n2 || k<n3); ){
                
                int mini = getmini(i, j, k, A, B, C, n1, n2, n3), count=0;
                
                (i<n1 && A[i] == mini)? (count++,i++) : 0;
                (j<n2 && B[j] == mini)? (count++,j++) : 0;
                (k<n3 && C[k] == mini)? (count++,k++) : 0;
                
                if(count==3){
                    
                    if( ans.size()==0 || ans.size()>0 && ans.back()!=mini)
                        ans.push_back(mini);
                }
            }
            return ans;
        }

};
