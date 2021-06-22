

// Qoestion Link :: "https://bit.ly/35JWGBC"


// Solution //

#include <bits/stdc++.h>

using namespace std;


class Solution{


    public:
        int *result;
        
        int *get_counts_array(int arr[], int n){

            int max_val = *max_element(arr,arr+n);
            int *occurence = new int[max_val+1];
            result = new int[n];

            // Tracing Every Number's Occurencee //
            for(int i=0;i<n;i++)
                occurence[arr[i]] += 1;

            // getting the count of numbers <= input_arr[i] //
            for(int i=1;i<=max_val;i++)
                occurence[i] += occurence[i-1];

            // Storing the result //
            for(int i=0;i<n;i++)
                result[i] = occurence[arr[i]-1];

            return result;
            
        }

};
