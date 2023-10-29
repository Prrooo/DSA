#include<bits/stdc++.h>
using namespace std;

bool foundTarget(vector<int> arr,int target){
	int n=arr.size();
	for(int i=0;i<n;i++){
		if(arr[i]==target){
			return true;
		}
	}
	return false;
}

bool searchMatrix(vector<vector<int>> &arr,int target){
	int n=arr.size();
	for(int i=n-1;i>=0;i--){
		if(arr[i][0]<=target){
			return foundTarget(arr[i],target);
		}
	}
	return false;
}

int main(){
	int n,m,target;
	cin>>n>>m>>target;
	vector<vector<int>> arr;
	for(int i=0;i<n;i++){
		vector<int> toPush;
		for(int j=0;j<m;j++){
			int x;
			cin>>x;
			toPush.push_back(x);
		}
		arr.push_back(toPush);
	}
	cout<<searchMatrix(arr,target);
	return 0;
}