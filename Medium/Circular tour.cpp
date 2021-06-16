

// Question Link :: "https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1"


// Solution //


class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int i=0,j=0,pumps_covered = 0, backup = 0;
       
       while(pumps_covered <= n){
           
           if( j<n ){
               
               if( backup < 0 ){
                 
                   if( j <= i )
                        return -1;
                   i = j;
                   backup = 0;
                   pumps_covered = 0;
               }
               else{
                    
                    backup += (p[j].petrol - p[j].distance);
                    pumps_covered += 1;
                    j += 1;
               }
           }
           else{
               j=0;
           }
           
       }
       return i;
       
    }
};
