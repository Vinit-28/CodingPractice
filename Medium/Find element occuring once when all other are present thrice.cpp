

// Question Link :: "https://practice.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1"


// Solution //

class Solution {
  public:
  
    int toDecimal(string bin){
        
        int decimal = 0;
        for(int i=31;i>=0;i--)
            if(bin[i]=='1')
                decimal += pow(2,(31-i));
        return decimal;
    }
    
    string toBinary(string val){
        
        string newVal = "";
        for(int i=0;i<32;i++)
            newVal += (val[i]=='0')? '1' : '0';
        
        int carry = 1;
        for(int i=31;i>=0;i--)
            if( carry==1 )
                (newVal[i]=='1')? (newVal[i]='0') : (newVal[i]='1', carry=0);
                
        return newVal;
    }
  
    int singleElement(int arr[] ,int n) {
        // code here
        
        int counter=0;
        string bin = "";
        
        for(int i=31;i>=0;i--,counter = 0){
            for(int j=0;j<n;j++){
                int bit = arr[j]>>i;
                if(bit&1)
                    counter++;
            }
            bin += (counter!=0 && counter%3!=0)? "1" : "0";
        }
        if( bin[0]=='1' )
            return -toDecimal(toBinary(bin));
        
        return toDecimal(bin);
    }
};