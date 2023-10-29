// https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/

#include<bits/stdc++.h>
using namespace std;

// brute force time complexity O(N) and space complexity O(N)
// we store the count of number upto N and whose count is greater than 2
// is the repeating number and whose count is 0 is missing number 

// vector<int> findMissingRepeatingNumbers(vector<int> &arr){
// 	int miss=-1,repeat=-1;
// 	int n=arr.size();
// 	vector<int> ans;
// 	int count[n+1]={0};
// 	for(int i=0;i<n;i++){
// 		count[arr[i]]++;
// 	}
// 	for(int i=1;i<n+1;i++){
// 		if(count[i]==0){
// 			miss=i;
// 		}
// 		if(count[i]>1){
// 			repeat=i;
// 		}
// 	}
// 	ans.push_back(repeat);
// 	ans.push_back(miss);
// 	return ans;
// 	// return {repeat,miss};  // this will also work =======
// }

// optimal approach (mathematical)
// we store the sum of N natural number in SN and sum of all the element in the S
// and subtract them we get our 1st equation then we store the sum of sqare of each
// element and the sqare of N natural number and subtract them then we get our second 
// equation then solve both equation 

vector<int> findMissingRepeatingNumbers(vector<int> &arr){
	long long n=arr.size();
	long long SN=(n*(n+1)/2); // sum of natural number upto N
	long long S2N=(n*(n+1)*(2*n+1))/6; // sum of square upto n
	long S=0,S2=0;
	for(int i=0;i<n;i++){
		S+=(long long)arr[i]; // sum of all the element in the array
		S2+=(long long)arr[i]*(long long)arr[i]; // sum of square in the array
	}
	cout<<S<<" "<<S2<<endl;
	long long val1=S-SN; // x-y
	long long val2=S2-S2N; // x^2 + y^2
	val2=val2/val1; // x+y 
	long long x=(val1+val2)/2;
	long long y=x-val1;
	return {(int)x,(int)y};
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
	vector<int> ans=findMissingRepeatingNumbers(arr);	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}