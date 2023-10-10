//solution 1 using kadane algorithm



long long maxSubarraySum(vector<int> arr, int n)
{
    long long maxi = 0; 
    long long maxstart=0;
    for(int i=0;i<n;i++){
        maxstart=maxstart+arr[i];
        maxi=max(maxi,maxstart);
        if(maxstart<0){
            maxstart=0;
        }
    }
    return maxi;
    
}






















long long maxSubarraySum(vector<int> arr, int n)
{
    long long maxi = 0; 
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; #restart array

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
    // Write your code here.
}