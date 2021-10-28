

// Question Link :: "https://practice.geeksforgeeks.org/problems/concatenation-of-zig-zag-string-in-n-rows0308/1#"


// Solution //

class Solution{
    public:

    int getDistance(int row, char direction, int N){
        
        int dist = 0;
        if( direction == '^' ) dist = ((row*2)-1);
        else dist = (((N-1)-row)*2)-1;
        
        return dist;
    }
    
    string convert(string s, int N) {
        //code
        
        int start = 0, len=s.length();
        string ans = "";
        if( N==1 || len <= N) return s;
        for(int i=0; i<N; i++, start++){
            
            int dist_up = getDistance(i, '^', N);
            int dist_down = getDistance(i, 'v', N);
            int index=start;
            char direction = 'v';
            while(index<len){
                
                ans += s[index];
                if( direction == 'v' ){
                    if( dist_down >= 1 ) index += (dist_down+1);
                    else index += (dist_up+1);
                    direction = '^';
                }
                else{
                    if( dist_up >= 1 ) index += (dist_up+1);
                    else index += (dist_down+1);
                    direction = 'v';
                }
            }
        }
        return ans;
    }
};