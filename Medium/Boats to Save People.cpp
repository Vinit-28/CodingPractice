

// Question Link :: "https://leetcode.com/problems/boats-to-save-people/"


// Solution //

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int boats = 0, n = people.size();
        int isVisited[n];
        sort(people.begin(), people.end());
        memset(isVisited, 0, sizeof(isVisited));

        for(int left = 0, right = n-1; left<n; left++){
            
            if( isVisited[left] == 0 ){
                
                while( left < right && (people[left] + people[right]) > limit ) right -= 1;

                if( right > left ) isVisited[right] = 1, right -= 1;
                
                boats += 1;
                isVisited[left] = 1;
            }
        }
        return boats;
    }
};