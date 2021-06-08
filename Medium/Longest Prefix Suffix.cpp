

// Question Link :: "https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1#"



// Solution //

class Solution{
public:		
	
	string prefix="",sufix="";
	int lps(string s)
	{
	    // Your code goes here
	    int max_len=s.length()-1,temp=max_len;
	    get_req(max_len+1,s);
	    
	    while(max_len){
	        
	        if( is_same(max_len, temp-max_len) )
	            return max_len;
	        
	        max_len-=1;
	    }
	    return 0;
	}
	
	bool is_same( int pre_len, int suf_i ){
	    
	    for(int i=0;i<pre_len;i++,suf_i++){
	        
	        if( prefix[i] != sufix[suf_i] )
	            return false;
	    }
	    return true;
	}
	
	
	void get_req(int len, string str){
	    
	    prefix=sufix="";
	    for(int i=0;i<len;i++){
	        
	        if( i != len-1 ){
	            
	            prefix+=str[i];
	        }
	        
	        if( i>0 ){
	            
	            sufix+=str[i];
	        }
	        
	    }
	}
	
};