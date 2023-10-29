#include<bits/stdc++.h>
using namespace std;

void printArray(vector<vector<int>> &arr){
	int n=arr.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	vector<vector<int>> ans;
	int n=arr.size();
	int start=-1,end=-1;
	for(int i=0;i<n;i++){
		if(i==0){
			start=arr[i][0];
			end=arr[i][1];
		}
		else if(start<=arr[i][0] && arr[i][0]<=end && end<arr[i][1]){
			end=arr[i][1];
		}
		if(end<arr[i][0]){
			vector<int> toPush;
			toPush.push_back(start);
			toPush.push_back(end);
			ans.push_back(toPush);
			start=arr[i][0];
			end=arr[i][1];
		}
	}
	if(start!=-1 && end!=-1){
		vector<int> toPush;
		toPush.push_back(start);
		toPush.push_back(end);
		ans.push_back(toPush); 
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> arr;
	for(int i=0;i<n;i++){
		vector<int> test;
		for(int j=0;j<2;j++){
			int x;
			cin>>x;
			test.push_back(x);
		}
		arr.push_back(test);
	}
	arr=mergeOverlappingIntervals(arr);
	printArray(arr);
	return 0;
}