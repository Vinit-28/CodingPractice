

// Question Link :: "https://leetcode.com/problems/3sum-with-multiplicity/"



// Solution //

class Solution {
public:
    long mod = 1000000007;
    
    long multiply(long a, long b){
        return ((a%mod)*(b%mod))%mod;
    }
    
    long add(long a, long b){
        return ((a%mod)+(b%mod))%mod;
    }
    
    int threeSumMulti(vector<int>& arr, int target) {
        
        int n = arr.size();
        long ans = 0;
        sort(arr.begin(), arr.end());
        
        for(int i=0;i<n;i++){
            auto temp = getCount(arr, i+1, n-1, i, target);
            ans = add(ans, temp);
        }
        return ans%mod;
    }
    
    long getCount(vector<int> &arr, int left, int right, int &index, int &target){
        
        long count = 0;
        while( left < right ){
            int sum = (arr[left] + arr[right] + arr[index]);
            
            if( sum < target ) left += 1;
            else if( sum > target ) right -= 1;
            else{
                
                if( arr[left] != arr[right] ){
                    
                    long leftOccur = 1, rightOccur = 1, temp1 = left+1, temp2 = right-1;

                    while( temp1 < right && arr[temp1] == arr[left] ) leftOccur += 1, temp1+=1;

                    while( temp2 > left && arr[temp2] == arr[right] ) rightOccur += 1, temp2-=1;
                    
                    count = add(count, multiply(leftOccur, rightOccur));
                    left = temp1, right = temp2;
                }
                else{
                    long temp = (right-left);
                    count = add(count, multiply(temp, add(temp, 1))/2);
                    return count%mod;
                }
            }
        }
        return count%mod;
    }
};