#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/permutations/

void solve(vector<int> &arr,vector<vector<int>> &ans,int feq[],vector<int> &toPush){
	if(toPush.size()==arr.size()){
		ans.push_back(toPush);
		return ;
	}
	for(int i=0;i<arr.size();i++){
		if(feq[i]==0){
			toPush.push_back(arr[i]);
			feq[i]=1;
			solve(arr,ans,feq,toPush);
			feq[i]=0;
			toPush.pop_back();
		}	
	}
}

vector<vector<int>> permute(vector<int>& arr){
	vector<vector<int>> ans;
	vector<int> toPush;
	int feq[arr.size()];
	for(int i=0;i<arr.size();i++){
		feq[i]=0;
	}
	solve(arr,ans,feq,toPush);
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	vector<vector<int>> ans=permute(arr);
	return 0;
}