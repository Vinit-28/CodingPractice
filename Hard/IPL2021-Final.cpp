

//  Question Link :: "https://practice.geeksforgeeks.org/problems/3b47f0ad00f953dd514235ddec54e39fdc297dda/1"




// Solution //

class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        
        int max_count=0,len=s.length(),curr_count=0;
        // bool is_prev_pair = false;
        
        for (int i=0;i<len;i++)
        {
            if(s[i]=='(')
            {
                int open=1,pair=0,temp=0,j;
                
                for(j=i+1,curr_count=0;j<len;j++)
                {
                    if(s[j]=='(')
                        open+=1;
                    else
                        open-=1,pair+=1;
                    
                    if(open<0)
                        break;
                    
                    if(open == 0)
                    {
                        curr_count += (pair*2);
                        temp = j;
                        pair=0;
                    }
                }
                
                if(max_count < curr_count)
                {
                    i=temp+1;
                    max_count = curr_count;
                }
            }
            
        }
        
        return max_count;
    }
    
    
};