

//   Question Link :: "https://practice.geeksforgeeks.org/problems/nth-natural-number/1#"



// Solution //


class Solution{
	public:
    long long findNth(long long N)
    {
        // code here.
        long long int nth_number = 0;
        string temp = "";
        int l=0;
        
        while(N>0){
            
            temp += char((N%9)+48);
            N/=9;
            l++;
        }
        l--;
        while(l>=0){
            
            nth_number = (nth_number*10)+(int(temp[l])-48);
            l--;
        }
        
        return nth_number;
    }
};
