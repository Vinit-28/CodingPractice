

// Question Link :: "https://leetcode.com/problems/candy/"



// Solution //

class Solution {
public:
    
    int getCount(vector<int> &arr, int index, int &n){
        
        int count = 1;
        for(int i=index+1; i<n; i++){
            if( arr[i] >= arr[i-1]  ) return count;
            count += 1;
        }
        return count;
    }
    
    int candy(vector<int>& ratings) {
        
        int index = 0, n=ratings.size(), candies[n];
        int ans = 0;
        while( index < n ){
            
            int count = getCount(ratings, index, n);
            
            if( index != 0 && count < (candies[index-1]+1) ){
                candies[index] = ratings[index-1] != ratings[index]? candies[index-1]+1 : count;
                ans += candies[index], index+=1, count-=1;
            }
            while(count)
                candies[index]=count, ans+=count, count-=1, index+=1;
        }
        return ans;
    }
};