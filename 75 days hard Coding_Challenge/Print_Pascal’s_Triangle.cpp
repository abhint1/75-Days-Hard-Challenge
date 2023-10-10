#include <iostream>
#include <vector>
vector<vector<int>> pascalTriangle(int N) {
    
    if(N==1){
        return {{1}} ;

    }

    // list of n list with all elements 0 except first and last element
    vector<vector<int>> prev_rows(N);
    for(int i=0;i<N;++i){
        prev_rows[i].resize(i+1,0);
        prev_rows[i][0]=1;
        prev_rows[i][i]=1;

    }
    // pascles triangle prev_rows[i][j]=prev_rows[i-1][j-1]+prev_rows[i-1][j]   sum of upper two equals to lower element
    for(int i=2;i<prev_rows.size();++i){
        for(int j=1;j<prev_rows[i].size()-1;++j){
            prev_rows[i][j]=prev_rows[i-1][j-1]+prev_rows[i-1][j];
    
        }

    }
    return prev_rows;
   
}