

//   Question Link :: "https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1"



// Solution //


class Solution {
  public:
    
    
    int checkMirrorTree(int n, int e, int a[], int b[]) {
        // code here
        
        map<int, vector<int>> treelinks1, treelinks2;
        bool isMirror;
        
        getTreeLinks(e,a,treelinks1);
        getTreeLinks(e,b,treelinks2);
        
        
        for(auto key : treelinks1){
            
            auto t1 = key.second;
            auto t2 = treelinks2[key.first];
            
            int t1_size = t1.size(),t2_size = t2.size();

            if( t1_size != t2_size )
                return 0;
            else{
                
                for(int i=0,j=t2_size-1;i<t1_size;i++,j--){
                    
                    if( t1[i] != t2[j] )
                        return 0;
                }
            }
        }
        return 1;
        
    }

    
    void getTreeLinks(int e, int links[], map<int, vector<int>> &treelinks){
        
        for(int i=0;i<(e*2);i+=2){
            
            treelinks[links[i]].push_back(links[i+1]);
        }
    }
    
};
