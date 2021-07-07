

// Question Link :: "https://practice.geeksforgeeks.org/problems/find-first-and-last-occurrence-of-x0849/1"


// Solution //

{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        
        int index, len = v.size();
        
        if( isThere(v, x, index) ){
            
            int left = index, right = index;
            
            while( (left-1)>=0 && v[left-1] == x )
                left-=1;
            
            while( (right+1)<len && v[right+1] == x )
                right+=1;
            
            return {left,right};
        }
        
        return {-1,-1};
    }
    
    
    bool isThere(vector<long long> v, long long x, int &mid){
        
        int l=0, u=v.size();
        mid = (l+u)/2;
        
        while(l<=u){
            
            if( v[mid] < x )
                l = mid+1;
            else if( v[mid] > x )
                u = mid-1;
            else
                return true;
            
            mid = (l+u)/2;
        }
        
        return false;
    }
    
};
