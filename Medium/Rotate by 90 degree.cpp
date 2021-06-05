

// Question Link :: "https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1"



// Solution //


void swap(int &a, int &b){
    
    int temp=a;
    a=b,b=temp;
}

void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int i,j,n = matrix.size(),col_left=n,rounds=0,temp;
    
    for(rounds; rounds<(n/2); rounds++,col_left--){
        
        for(i=col_left-1, j=rounds; i>rounds; i--, j++){
            
            temp = matrix[rounds][i];
            
            swap(temp,matrix[j][rounds]);
            
            swap(temp,matrix[col_left-1][j]);
            
            swap(temp,matrix[i][col_left-1]);
            
            swap(temp,matrix[rounds][i]);
        }
        
    }
    
}
