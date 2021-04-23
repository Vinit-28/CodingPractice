


//   Question Link :: "https://practice.geeksforgeeks.org/problems/269f61832b146dd5e6d89b4ca18cbd2a2654ebbe/1"



class Solution {
public:
    int helpaterp(vector<vector<int>> lst)
    {
        //code here
        int R = lst.size(),C = lst[0].size();
        vector<vector<int>> lst_copy = lst;
        
        
        int total_time = 0,row,col,changed,count_1;
        
        while (true){
            row = changed = count_1 = 0;
            while (row < R){
                col = 0;
                while (col < C){
                    
                    if (lst[row][col]==2){
                        
                        // # Checking Left and Right
                        if ((col-1)>=0 && lst[row][(col-1)]==1){
                            lst_copy[row][col-1] = 2;
                            lst[row][col-1] = 3;
                            changed+=1;
                            count_1 -= 1;
                        }
                        
                        if ((col+1)<C && lst[row][(col+1)]==1){
                            lst_copy[row][col+1] = 2;
                            lst[row][col+1] = 3;
                            changed+=1;
                        }
                        
                        
                        // # Checking Up and Down
                        if ((row-1)>=0 and lst[row-1][(col)]==1){
                            lst_copy[row-1][col] = 2;
                            lst[row-1][col] = 3;
                            changed+=1;
                            count_1 -= 1;
                        }
                            
                        if ((row+1)<R && lst[row+1][(col)]==1){
                            lst_copy[row+1][col] = 2;
                            lst[row+1][col] = 3;
                            changed+=1;
                        }
                    }
                    
                    else if (lst[row][col] == 1)
                        count_1+=1;
                    
                    col+=1;
                }
                
                row+=1;
            }
            
            
            if (count_1 == 0)
                return total_time +1;
                
            if (changed == 0)
                if (count_1 > 0)
                    return -1;
        
            total_time +=1;
            lst = lst_copy;
        }
                
    }
};
