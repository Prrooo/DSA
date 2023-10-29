// https://leetcode.com/problems/maximum-subarray/description/

#include<bits/stdc++.h>
using namespace std;

// brute force approach time complexity O(n^2) =============
// int maxSubArray(vector<int> &arr){
// 	int ans=INT_MIN,curr=0,n=arr.size();
// 	for(int i=0;i<n;i++){
// 		curr=0;
// 		for(int j=i;j<n;j++){
// 			curr+=arr[j];
// 			ans=max(curr,ans);
// 		}	
// 	}
// 	return ans;
// }

// most optimal solution time compexity O(n) ==============

int maxSubArray(vector<int> &arr){
	int ans=INT_MIN,curr=0;
	for(int i=0;i<arr.size();i++){
		curr+=arr[i];
		ans=max(ans,curr);
		if(curr<0){
			curr=0;
		}
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	cout<<maxSubArray(arr);
	return 0;
}