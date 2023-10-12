#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	int hashmap[n+1]={0};
	for(int i=0;i<n;i++){
		hashmap[arr[i]]++;
	}
	int duplicate=0;
	for(int i=0;i<n;i++){
		if(hashmap[i]>1){
			return i;
		}
	}
	// Write your code here.
}
