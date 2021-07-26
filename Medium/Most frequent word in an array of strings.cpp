

// Question Link :: "https://practice.geeksforgeeks.org/problems/most-frequent-word-in-an-array-of-strings3528/1"


// Solution //

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        map<string, int> frequency, pos;
        int maxFre = INT_MIN, lastOccur;
        string ans;
        for(int i=0;i<n;i++){
            frequency[arr[i]] += 1;
            if( frequency[arr[i]] == 1 )
                pos[arr[i]] = i;
        }
        
        for(int i=0;i<n;i++){
            
            if( maxFre < frequency[arr[i]] )
                maxFre = frequency[arr[i]], lastOccur = pos[arr[i]], ans = arr[i];
            
            else if( maxFre == frequency[arr[i]] ){
                if( pos[arr[i]] > lastOccur )
                    lastOccur = pos[arr[i]], ans = arr[i];
            }
        }
        return ans;
    }
};
