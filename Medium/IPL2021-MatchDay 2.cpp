

//  Question Link :: "https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1"



// Solution //

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) 
    {
        // your code here
        
        int m_i = get_max_index(0,k-1,arr), arr_i = m_i;

        
        vector<int> res;

        res.push_back(arr[arr_i]);
        // cout<<m_i<<endl;
    
    
        for (int i=k;i<n;i++)
        {
            process_data(m_i,arr_i,i,arr,k);
            res.push_back(arr[arr_i]);
        }
        return res;
    }
    
    
    
    int get_max_index(int start,int end,vector<int> &arr)
    {
        int m=0,index;
        for(int i=0;start<=end;start++,i++)
        {
            if(arr[start]>m)
            {
                m=arr[start];
                index=i;
            }
        }
        return index;
    }
    
    
    
    void process_data(int &m_i, int &arr_i, int curr_i,vector<int> &arr, int k)
    {
        if(m_i > 0)
            m_i--;
        else
        {
            m_i = get_max_index(arr_i+1, curr_i,arr);
            arr_i+= (m_i+1); 
            return;
        }
    
        if( arr[arr_i] <= arr[curr_i] )
        {
            m_i = k-1;
            arr_i = curr_i;
        }
    }
    
    
    
    
};
