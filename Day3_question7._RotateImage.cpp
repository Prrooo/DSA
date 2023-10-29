#include<bits/stdc++.h>
using namespace std;

void printArray(vector<vector<int>> &arr){
	int n=arr.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

// so the brute force == is to take another 2D matrix which increase the space complexity
// to O(n^2) and time O(n^2);

// ===================

// optimize opraoch 

// 1st we take the transpose of the matrix and perform the 
// reverse algo in each row of the of the array 
// time Complexity O(n^2) space compl O(1);


void rotate(vector<vector<int>> &arr){
	int n=arr.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			swap(arr[i][j],arr[j][i]);
		}
	}
	for(int i=0;i<n;i++){
		reverse(arr[i].begin(),arr[i].end());
	}
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> arr;
	for(int i=0;i<n;i++){
		vector<int> test;
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			test.push_back(x);
		}
		arr.push_back(test);
	}
	rotate(arr);
	printArray(arr);
	return 0;
}