

// Question Link :: "https://leetcode.com/problems/interval-list-intersections/"


// Solution //

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        int index1=0,index2=0, n1=firstList.size(), n2=secondList.size();
        vector<vector<int>> ans;
        
        while(index1<n1 && index2<n2){
            
            if( firstList[index1][0] >= secondList[index2][0] && firstList[index1][0] <= secondList[index2][1] ){
                ans.push_back({firstList[index1][0], min(firstList[index1][1], secondList[index2][1]) });
            }
            else if( firstList[index1][1] >= secondList[index2][0] && firstList[index1][1] <= secondList[index2][1] ){
                ans.push_back({secondList[index2][0], min(firstList[index1][1], secondList[index2][1]) });
            }
            else if( secondList[index2][0] >= firstList[index1][0] && secondList[index2][0] <= firstList[index1][1] ){
                ans.push_back({secondList[index2][0], min(firstList[index1][1], secondList[index2][1]) });
            }
            
            ( firstList[index1][1] < secondList[index2][1] )? index1++ : index2++;
        }
        
        return ans;
    }
};