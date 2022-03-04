

// Question Link :: "https://leetcode.com/problems/multiply-strings/"


// Solution //

class Solution {
public:
    
    // Function to Multiply two characters (digits) //
    char multiplyChar(char &a, char &b, int &carry){
        
        int n1 = (a-48), n2 = (b-48);
        string temp = to_string( (n1*n2)+carry );
        char ans;
        
        if( temp.length() > 1 ) carry = temp[0]-48, ans = temp[1]; 
        else carry = 0, ans = temp[0];
        
        return ans;
    }
    
    
    // Function to add two characters (digits) //
    char addChar(char &a, char &b, int &carry){
        
        int n1 = (a-48), n2 = (b-48);
        string temp = to_string( n1+n2+carry );
        char ans;
        
        if( temp.length() > 1 ) carry = temp[0]-48, ans = temp[1]; 
        else carry = 0, ans = temp[0];
        
        return ans;
    }
    
    
    // Function to add zeroes in the starting of the string //
    void addLeadingZeroes(string &s, int zeroes){
        string pre = "";
        while(zeroes--) pre += "0";
        s = pre + s;
    }
    
    
    // Function to add zeroes in the end of the string //
    void addTrailingZeroes(string &s, int zeroes){
        while(zeroes--) s += "0";
    }
    
    
    // Function to Add two strings ( Example : "123" + "123" = "246" )//
    string addTwoStrings(string &s1, string &s2){
        
        string ans = "";
        int len = s1.length(), carry=0;
        
        for(int i=len-1;i>=0;i--){
            ans += addChar(s1[i], s2[i], carry);
        }
        if( carry > 0 ) ans += to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    
    // Function to Multiply two strings //
    string multiply(string num1, string num2) {
        
        
        string sum = "0", temp;
        int l1 = num1.length(), l2 = num2.length(), carry, tempInt;
        
        if( l1 > l2 ){
            tempInt = l1, l1 = l2, l2 = tempInt;
            temp = num1, num1 = num2, num2 = temp;
        }
        
        for(int i=l1-1, count=0; i>=0; i--, count++){
            
            if( num1[i] == '0' ) continue;
            
            carry = 0, temp = "";
            for(int j=l2-1; j>=0; j--){
                
                temp += multiplyChar(num1[i], num2[j], carry);
            }
            if( carry > 0 ) temp += to_string(carry);
            
            reverse(temp.begin(), temp.end());
            addTrailingZeroes(temp, count);
            int tLen = temp.length(), sLen = sum.length();
            addLeadingZeroes(sum, tLen-sLen);
            
            sum = addTwoStrings(temp, sum);
        }
        return sum;
    }
};