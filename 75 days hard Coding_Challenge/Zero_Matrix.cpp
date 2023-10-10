#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	unordered_set<int> iSet;
    unordered_set<int> jSet;

        // Find the rows and columns that need to be set to zero
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    iSet.insert(i);
                    jSet.insert(j);
                }
            }
        }

        // Set rows to zero
        for (int i : iSet) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = 0;
            }
        }

        // Set columns to zero
        for (int j : jSet) {
            for (int i = 0; i < n; ++i) {
                matrix[i][j] = 0;
            }
        }

	return matrix;


}