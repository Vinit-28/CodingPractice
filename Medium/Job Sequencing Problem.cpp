

// Question Link :: "https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1"


// Solution //

class Solution 
{
    public:
    
    static bool comparison(Job a, Job b){
        return a.profit>b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int maxProfit = 0, jobsDone = 0, maxDeadline = INT_MIN;
        
        for(int i=0; i<n; i++)
            maxDeadline = max(maxDeadline, arr[i].dead);
        
        sort(arr, arr+n, comparison);
        vector<bool> allotments(maxDeadline, false);
        
        // Solving the Problem //
        for(int i=0; (i<n && maxDeadline>0); i++){
            
            int allotedTime = arr[i].dead-1;
            while(allotedTime >= 0){
                
                if( allotments[allotedTime] == false ){
                    allotments[allotedTime] = true;
                    maxProfit += arr[i].profit;
                    jobsDone += 1;
                    break;
                }
                allotedTime-=1;
            }
        }
        
        return {jobsDone,maxProfit};
    } 
};
