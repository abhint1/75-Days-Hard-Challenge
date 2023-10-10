

vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); 

    
    int ind = -1; 
    int i = n - 2;
    while (i >= 0) {
        if (A[i] < A[i + 1]) {
            
            ind = i;
            break;
        }
        i--;
    }

    
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    
    i = n - 1;
    while (A[i] <= A[ind]) {
        i--;
    }
    swap(A[i], A[ind]);

 
    reverse(A.begin() + ind + 1, A.end());

    return A;
}