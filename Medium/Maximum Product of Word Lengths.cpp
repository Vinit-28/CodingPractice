

// Question Link :: "https://leetcode.com/problems/maximum-product-of-word-lengths/"


// Solution //

class Solution {
public:
    
    int getMask(char &ch){
        return (1<<(ch-97));    
    }
    
    bool doShareCommonLetters(int &bits1, int &bits2){
        
        return (bits1 & bits2);
    }
    
    int maxProduct(vector<string>& words) {
        
        int ans=0, n=words.size();
        int bits[n];
        memset(bits, 0, sizeof(bits));
        
        for(int i=0;i<n;i++){
            for(auto &ch : words[i]){
                bits[i] = (bits[i] | getMask(ch));
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if( doShareCommonLetters(bits[i], bits[j]) == false ){
                    int prod = (words[i].length() * words[j].length());
                    ans = max(ans, prod);
                }
            }
        }
        return ans;
    }
};