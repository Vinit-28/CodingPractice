

// Question Link :: "https://leetcode.com/problems/zigzag-conversion/"


// Solution //

class Solution {
public:
    string convert(string s, int numRows) {
        
        int len = s.length(), temp = len, totalCol=0, index, row, col;
        char turn='N';
        
        if( len <= numRows || numRows==1 ) return s;
        
        while(temp > 0)
            (turn=='N')? (temp-=numRows, turn='Z', totalCol+=1) : (temp-=(numRows-2), turn='N', totalCol+=(numRows-2));
   
        string ans="";
        char mat[numRows][totalCol];
        memset(mat, '_', sizeof(mat));
        turn = 'N', row=0, col=0, index=0;
        
        while(index<len){
            
            if( turn=='N' ){
                row=0, turn='Z';
                while(row<numRows && index<len && col<totalCol) mat[row][col]=s[index], index++, row++;
            }
            else{
                row=numRows-2, col=col+1, turn='N';
                while(row>0 && index<len && col < totalCol) mat[row][col]=s[index], index++, row-=1, col+=1; 
            }
        }
        
        for(int i=0;i<numRows;i++)
            for(int j=0;j<totalCol;j++)
                if( mat[i][j] != '_' ) ans += mat[i][j];
        
        return ans;
    }
};