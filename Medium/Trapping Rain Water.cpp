

// Question Link :: "https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1"


// Solution //

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    // Function to find the trapped water between the blocks.
    long long int getWaterTrapped(int arr[], int b1, int b2, int waterLevel){
        
        long long int sum=0;
        for(int i=b1+1;i<b2;i++) sum += (waterLevel-arr[i]);
        return sum;
    } 
    
    void setMaxs(int arr[], int maxs[], int n){
        
        vector<int> s = {n-1};
        maxs[n-1] = s[0];
        
        for(int i=n-2;i>=0;i--){
            
            while(s.empty()==false && arr[s.back()] < arr[i]) s.pop_back();
            
            if( s.empty() ) maxs[i]=i, s.push_back(i);
            else maxs[i] = s.back(), s.push_back(i);
        }
    }

    long long trappingWater(int arr[], int n){
        // code here
        long long int ans=0;
        int bIndex=0, maxs[n], i=0;
        setMaxs(arr, maxs, n);
        
        while(i<n)
            if( maxs[i] == i ) bIndex=i,i++;
            
            else{
                int lbIndex = maxs[i], tempIndex = i;
                
                while( arr[bIndex] >= arr[ maxs[tempIndex] ] && maxs[tempIndex] != tempIndex ) lbIndex = tempIndex = maxs[tempIndex]; 
                
                int waterLevel = (arr[lbIndex] >= arr[bIndex])? arr[bIndex] : arr[lbIndex];
                ans += getWaterTrapped(arr, bIndex, lbIndex, waterLevel), i = bIndex = lbIndex;
            } 
        return ans;
    }
};