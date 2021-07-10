

// Question Link :: "https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1"


// Solution //

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size)
    {
        // your code here
        int majEle = arr[0],counter=1;
        for(int i=1;i<size;i++){
            if( arr[i] == majEle )
                counter+=1;
            else
                counter-=1;
            
            if( counter == 0 )
                majEle = arr[i], counter=1;
        }
        
        counter=0;
        for(int i=0;i<size;i++)
            if(majEle == arr[i])
                counter+=1;
        
        if( counter > (size/2) )
            return majEle;
        return -1;
    }
};