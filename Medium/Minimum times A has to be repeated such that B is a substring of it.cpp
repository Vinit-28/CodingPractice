

// Question Link :: "https://practice.geeksforgeeks.org/problems/5ef42ba605fff6cd60b1b2dd2ee230ade1fa25b0/1#"


// Solution //

class Solution {
  public:
    int minRepeats(string a, string b) {
        // code here

        int ans = INT_MAX, len1 = a.length(), len2 = b.length();
        
        for(int i=0;i<len1;i++){
            
            if( b[0] == a[i] ){
                
                int bIndex = 0, aIndex = i, repeats = 0;
                bool isMatch = true;
                
                while( bIndex < len2 ){
                    
                    if( b[bIndex] != a[aIndex] ){
                        isMatch = false;
                        break;
                    }
                    aIndex +=1, bIndex += 1;
                    if( aIndex >= len1 && bIndex < len2 ) repeats+=1, aIndex = 0;
                }
                if( isMatch ){
                    // cout<<i<<" "<<repeats<<endl;
                    ans = min(ans, repeats+1);
                } 
            }
        }
        return (ans == INT_MAX)? -1 : ans;
    }
};