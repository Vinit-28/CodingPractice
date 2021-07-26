

// Question Link :: "https://practice.geeksforgeeks.org/problems/sort-the-given-array-after-applying-the-given-equation0304/1"


// Solution //
vector<long long> sortArray(vector<long long>arr, int n, long long A, long long B, long long C){
    //complete the function here
    priority_queue<long long, vector<long long>, greater<long long>> heap;
    for(int i=0;i<n;i++){
        heap.push(( (A * arr[i]*arr[i]) + (B*arr[i]) + C ));
    }
    for(int i=0;i<n;i++,heap.pop())
        arr[i] = heap.top();
    return arr;
}