#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{   

	int hash[n+1]={0};

    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    
    int repeat=0,miss=0;
    for(int i=1;i<n+1;i++){
        if(hash[i]==2){
  
            repeat=i;
        }else if(hash[i]==0){
            miss=i;
        }
    }
    return {miss,repeat};

	
}
