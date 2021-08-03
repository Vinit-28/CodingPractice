

// Question Link :: "https://practice.geeksforgeeks.org/problems/meta-strings5713/1"


// Solution //

bool metaStrings (string s1, string s2)
{
    // your code here
    int len1 = s1.length(), len2 = s2.length(), arr[2], count=0;
    if( len1 != len2 )
        return false;
    
    for(int i=0;i<len1;i++){
        
        if( s1[i] != s2[i] && count>=2 )
            return false;
        else if( s1[i] != s2[i] )
            arr[count] = i, count++;
    }
    
    if( count!=2 || s1[arr[0]] != s2[arr[1]] || s1[arr[1]] != s2[arr[0]] )
        return false;
    
    return true;
}