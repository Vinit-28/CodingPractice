

// Question Link :: "https://practice.geeksforgeeks.org/problems/find-the-frequency/1" 


// Solution //

int findFrequency(vector<int> v, int x){
    // Your code here
    
    int fre =0,n=v.size();
    for(int i=0,j=n-1; i<=j; i++,j-- ){
        
        if( v[i] == x )
            fre+=1;
        
        if( v[j] == x )
            fre+=1;
        
        if( i==j && x==v[i] )
            fre-=1;
    }
    return fre;
}