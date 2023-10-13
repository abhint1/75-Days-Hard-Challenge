#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	for(int i=0;i<b.size();i++){
		a.push_back(b[i]);
		
	}
	b.clear();
	sort(a.begin(),a.end());
	
	
}


//2

/*
Time Complexity: O(N * (M + N) + MlogM), where 'N' is the size of 'A' and 'M' is the size of 'B'.
Space Complexity: O(1)
*/

#include<vector>

// Function to swap two integers 'a' and 'b'.
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n = a.size(), m = b.size();
	
	// Iterating over the positions of 'N' smallest integers.
	for(int i = 0; i < n; ++i){
		int flag = i;
		int least = a[i];
		
		// Finding the minimum among the remaining elements of 'A'.
		for(int j = i; j < n; ++j){
			if(a[j] < least){
				least = a[j];
				flag = j;
			}
		}
		
		// Finding the minimum among the elements of 'B'.
		for(int j = 0; j < m; ++j){
			if(b[j] < least){
				least = b[j];
				flag = j;
			}
		}
		
		// Swapping 'A[i]' with the least element.
		if(flag < n && flag >= i && a[flag] == least)
			swap(a[i], a[flag]);
		else
			swap(a[i], b[flag]);
	}
	
	// Sorting the array 'B'.
	sort(b.begin(), b.end());
}

//3


 /*
Time Complexity: O(M + N + MlogM + NlogN), where 'N' is the size of 'A' and 'M' is the size of 'B'.
Space Complexity: O(1)
*/

#include<vector>

// Function to swap two integers 'a' and 'b'.
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n = a.size(), m = b.size();
	int i = 0, j = 0, k = n - 1;
	
	// Iterating over 'A' and 'B'.
	while(i <= k && j < m){
		if(a[i] < b[j]){
			++i;
		}
		else{
			
			// Swapping the current element of 'B' with the 'kth' element of 'A'.
			swap(a[k], b[j]);
			++j;
			--k;
		}
	}
	
	// Sorting the array 'A'.
	sort(a.begin(), a.end());
	
	// Sorting the array 'B'.
	sort(b.begin(), b.end());
} 


//4

/*
Time Complexity: O(M + N), where 'N' is the size of 'A' and 'M' is the size of 'B'.
Space Complexity: O(1)
*/

#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n = a.size(), m = b.size();
	
	// Maximum element we will use for Euclid's Lemma.
	const long long MX = 1e9 + 7;
	int i = 0, j = 0, k = 0;
	
	// Iterating over 'A' and 'B'.
	while(i < n && j < m && k < n + m){
		
		// Extracting the original numbers.
		long long originalNumberA = a[i] % MX;
		long long originalNumberB = b[j] % MX;
		
		// Comparing the original numbers.
		if(originalNumberA <= originalNumberB){
			if(k < n)
				a[k] += originalNumberA * MX;
			else
				b[k - n] += originalNumberA * MX;
			++i;
			++k;
		}
		else{
			if(k < n)
				a[k] += originalNumberB * MX;
			else
				b[k - n] += originalNumberB * MX;
			++j;
			++k;
		}
	}
	
	// Iterating over the remaining elements of 'B' (if any).
	while(j < m){
		long long originalNumberB = b[j] % MX;
		if(k < n)
			a[k] += originalNumberB * MX;
		else
			b[k - n] += originalNumberB * MX;
		++j;
		++k;
	}
	
	// Iterating over the remaining elements of 'A' (if any).
	while(i < n){
		long long originalNumberA = a[i] % MX;
		if(k < n)
			a[k] += originalNumberA * MX;
		else
			b[k - n] += originalNumberA * MX;
		++i;
		++k;
	}
	
	// Changing the elements of 'A' to the new numbers.
	for(int i = 0; i < n; ++i)
		a[i] /= MX;
	
	// Changing the elements of 'B' to the new numbers.
	for(int i = 0; i < m; ++i)
		b[i] /= MX;
}