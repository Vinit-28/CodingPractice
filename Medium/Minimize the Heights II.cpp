

//   Question Link :: "https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1"


// Solution //

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        
        int min_diff = -1, left=0, right=0, ele_count=0;
        
        vector<int> visit_count(n);
        
        vector<pair<int, int>> vec = get_pairs(arr,n,k);
        
        int l = vec.size();
        
        while(right<l){
            
            visit_count[vec[right].second] +=1;
            if(visit_count[ vec[right].second ] == 1){
                
                ele_count+=1;
            }
            
            if(ele_count==n){
                
                if(min_diff==-1){
                    min_diff = vec[right].first - vec[left].first;
                }
                else{
                    min_diff = min( ( vec[right].first - vec[left].first ), min_diff );
                }
                
                visit_count[vec[left].second] -= 1;
                
                if( visit_count[vec[left].second] == 0 ){
                    
                    ele_count-=1;
                }
                
                left+=1;
            }
            
            if(ele_count != n)
                right+=1;
            
        }
        
        return min_diff;
    }
    
    
    vector<pair<int, int>> get_pairs(int arr[], int n, int k){
        
        vector<pair<int, int>> vec;
        
        for(int i=0;i<n;i++){
            vec.push_back({arr[i]+k, i}); // first -> value, second -> index
            
            if(k<=arr[i]){
                vec.push_back({arr[i]-k, i});
            }
        }
        sort(vec.begin(),vec.end());
        return vec;
        
    }
    
};