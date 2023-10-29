#include<bits/stdc++.h>
using namespace std;

// my code======================

// void zeroRow(vector<vector<int>> &arr,int row){
// 	int n=arr[0].size();
//     for(int i=0;i<n;i++){
//         arr[row][i]=0;
//     }
// }

// void zeroCol(vector<vector<int>> &arr,int col){
// 	int m=arr.size();
//     for(int i=0;i<m;i++){
// 	    arr[i][col]=0;
//     }
// }

// void setZeroes(vector<vector<int>>& matrix) {
//     vector<pair<int,int>> vp;
//     int n=matrix.size();
//     int m=matrix[0].size();
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(matrix[i][j]==0){
//                 vp.push_back(make_pair(i,j));
//             }
//         }
//     }
//     for(int i=0;i<vp.size();i++){
//     	// cout<<vp[i].first<<" "<<vp[i].second<<endl;
//         zeroRow(matrix,vp[i].first);
//         zeroCol(matrix,vp[i].second);
//     }
// }

// =====================
void zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

void printVector(vector<vector<int>> &arr){
	int n=arr.size();
	int m=arr[0].size();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	vector<vector<int>> arr;
	for(int i=0;i<3;i++){
		vector<int> test;
		for(int j=0;j<3;j++){
			int x;
			cin>>x;
			test.push_back(x);
		}
		arr.push_back(test);
	}
	zeroMatrix(arr,3,3);
	cout<<"Printing the original 2d Vector "<<endl;
	printVector(arr);
	return 0;	
}