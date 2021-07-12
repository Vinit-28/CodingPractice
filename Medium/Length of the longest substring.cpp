

// Question Link :: "https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1"


// Solution //

class Solution{
    public:
    int longestUniqueSubsttr(string str){
        //code
        vector<int> indexes(26,-1);
        vector<bool> isExists(26,false);
        int startingIndex=0, maxAns = 0, len = 0;
        
        for(int i=0;i<str.length();i++){
            
            if( isExists[str[i]-97] && indexes[str[i]-97] >= startingIndex){
                
                len -= ((indexes[str[i]-97] - startingIndex)+1);
                
                if( len <= 0 )
                    startingIndex = i;
                else
                    startingIndex = indexes[str[i]-97]+1;
                
                len+=1;
                indexes[str[i]-97] = i;
            }
            else{
                
                len+=1;
                indexes[str[i]-97] = i;
                isExists[str[i]-97] = true;
            }
            
            maxAns = max(maxAns,len);
        }
        return maxAns;
    }
};