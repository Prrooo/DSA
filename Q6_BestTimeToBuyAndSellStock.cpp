#include<bits/stdc++.h>
using namespace std;

// time complexity of my program is O(N) and space complexity is O(N)

// void suffSum(vector<int> &arr,int suff[],int n){
// 	int currSum=INT_MIN;
// 	for(int i=n-1;i>=0;i--){
// 		currSum=max(currSum,arr[i]);
// 		suff[i]=currSum;
// 	}
// }

// int maxProfit(vector<int> &arr){
// 	int n=arr.size();
// 	int suff[n];
// 	suffSum(arr,suff,n);
// 	int ans=INT_MIN;
// 	int minEle=INT_MAX;
// 	for(int i=0;i<n-1;i++){
// 		minEle=min(minEle,arr[i]);
// 		ans=max(ans,suff[i+1]-minEle);
// 	}
// 	return ans<0 ? 0 : ans;
// }

// Best solution ==================== time complexity O(N and space O(1)===========

int maxProfit(vector<int> &arr){
	int profit=0;
	int minElement=INT_MAX;
	for(int i=0;i<arr.size();i++){
		minElement=min(minElement,arr[i]);
		profit=max(profit,arr[i]-minElement);
	}
	return profit;
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
	cout<<maxProfit(arr);
	return 0;
}