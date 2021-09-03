

// Question Link :: "https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1"


// Solution //

class Solution{
public:

    void process(int arr[], int &i, int pos[], int neg[], int &t_p, int &t_n, int &p_i, int &n_i, char turn){
        
        if( turn == '+' )
            (p_i < t_p)? (arr[i] = pos[p_i], p_i++) : (arr[i] = neg[n_i], n_i++);
        else
            (n_i < t_n)? (arr[i] = neg[n_i], n_i++) : (arr[i] = pos[p_i], p_i++);
    }

	void rearrange(int arr[], int n) {
	    // code here
	    int pos[n], neg[n], p_i=0, n_i=0;
	    
	    for(int i=0;i<n;i++)
	        (arr[i] >=0 )? (pos[p_i]=arr[i], p_i++) : (neg[n_i]=arr[i], n_i++);

	        
	    for(int i=0,pos_i=0,neg_i=0;i<n;i++){
	        
	        if( i==0 || arr[i-1] < 0 ){
	            process(arr, i, pos, neg, p_i, n_i, pos_i, neg_i, '+');
	        }
	        else
	            process(arr, i, pos, neg, p_i, n_i, pos_i, neg_i, '-');
	    }
	}
};
