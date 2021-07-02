

// Question Link :: "https://practice.geeksforgeeks.org/problems/a-simple-fraction0921/1"


// Solution //
class Solution
	public:
	string fractionToDecimal(int n, int d) {
	    // Code here
	    string ans = to_string(n/d);
	    
	    if( n%d != 0 ){
	        
	        ans += ".";
	        auto p = get_after_decimal((n%d),d);
	        
	        if( p.second == -1 )
	            ans += p.first;
	        else{
	            
	            bool is_paren_added = false,is_match;
	            for(int i=0;i<p.first.length();i++){
	                if(i==p.second)
	                    ans+="(";
	                ans+=p.first[i];
	            }
	            ans+=")";
	        }
	    }
	    return ans;
	}
	
	
	pair<string,int> get_after_decimal(int n, int d){
	    
	    string after_decimal="",temp;
	    map<int, bool> track;
	    map<int,int> track_pos;
	    int index=0;
	    n*=10;
	    
	    while(n!=0 && track[n]==false){
	        
	        track[n]=true;
	        
	        temp = to_string(n/d);
	        after_decimal += temp;
	        track_pos[n] = index;
	        n%=d;
	        n*=10;
	        index+=(temp.length());
	    }
	    
	    if(n==0)
	        return {after_decimal,-1};
	   
	    return {after_decimal,track_pos[n]};
	}
	
};
