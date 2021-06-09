

// Question Link :: "https://practice.geeksforgeeks.org/problems/print-anagrams-together/1"



// Solution //

vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    // Your Code Here
    map<string,vector<string>> table;
    int len = string_list.size();
    
    for(int i=0;i<len;i++){
        
        string temp = string_list[i];
        sort(temp.begin(),temp.end());
        table[temp].push_back(string_list[i]);
        
    }
    
    vector<vector<string>> ans;
    
    for(auto p : table){
        ans.push_back(p.second);
    }
    
    return ans;
    
}