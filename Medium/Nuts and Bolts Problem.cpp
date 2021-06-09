

// Question Link :: "https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1"



// Solution //

class Solution{
public:	

    map<char,int> n_counts,b_counts;
    
	void matchPairs(char nuts[], char bolts[], int n) {
	    
	    get_req(nuts,bolts,n);
	    string sequence = "!#$%&*@^~";
	    int index=0;
	    
	    for(auto ch : sequence){
	        
	        if( n_counts[ch]>0 && n_counts[ch] == b_counts[ch] ){
	            
	            nuts[index] = bolts[index] = ch;
	            index+=1;
	        }
	    }
	}
	
	void get_req(char nuts[],char bolts[],int n){
	    
	    for(int i=0;i<n;i++){
	        
	        n_counts[nuts[i]]+=1;
	        b_counts[bolts[i]]+=1;
	    }
	    
	}

};
