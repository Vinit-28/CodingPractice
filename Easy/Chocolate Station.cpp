

// Question Link :: "https://practice.geeksforgeeks.org/problems/chocolate-station2951/1"


// Solution //

int getChocolateCost(vector<int> arr, int rate){

    int bought = arr[0], balance = 0;
    
    for(int i=0;i<arr.size()-1;i++){
        
        int freeChoc = arr[i]-arr[i+1];
        if( freeChoc < 0 ){
            
            if( (freeChoc+balance)<0 )
                bought += abs(freeChoc+balance), balance = 0;
            else
                balance += freeChoc;
        }
        else
            balance += freeChoc;
    }
    return (bought*rate);
}