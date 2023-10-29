// https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array of N integers. 
// Find the elements that appear more than N/3 times in the array. 
// If no such element exists, return an empty vector.

// brute force approach we use map to store the count of the element and 
// return the element which has more count than n/3  

// vector<int> majorityElement(vector<int> &arr){
// 	map<int,int> m;
// 	vector<int> ans;
// 	int n=arr.size();
// 	for(int i=0;i<n;i++){
// 		m[arr[i]]++;
// 	}
// 	for(auto i : m){
// 		if(i.second >n/3){
// 			ans.push_back(i.first);
// 		}
// 	}
// 	return ans;
// }

// optimise aproach as we do in previous question majorityElement 
// as we notice that we have to find all element which occur more than
// N/3 where N is the size of array therefore there can only be at most 
// 2 element which can occur more than N/3 in a single array 
// therefore we take two vairiable ELe1,Ele2 and count1,count2 for 
// but element and use same approach as we did in previous question
// majorityELement increase count if the element is same 
// if count==0 the ele=currElement 
// else count-- for each element 
// the only edge case we have to take care of is that but Ele1,Ele2 should 
// not be same 

vector<int> majorityElement(vector<int> &arr){
	int Ele1,Ele2;
	int count1=0,count2=0,n=arr.size();
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(count1==0 && arr[i]!=Ele2){
			count1++;
			Ele1=arr[i];
		}
		else if(count2==0 && arr[i]!=Ele1){
			count2++;
			Ele2=arr[i];
		}
		else if(arr[i]==Ele1){
			count1++;
		}
		else if(arr[i]==Ele2){
			count2++;
		}
		else{
			count1--,count2--;
		}
	}
	// then we check if both the element count is greater than N/3;
	count1=0,count2=0;
	for(int i=0;i<n;i++){
		if(arr[i]==Ele1){
			count1++;
		}
		else if(arr[i]==Ele2){
			count2++;
		}
	}
	if(count1>n/3){
		ans.push_back(Ele1);
	}
	if(count2>n/3){
		ans.push_back(Ele2);
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int> ans;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	ans=majorityElement(arr);
	for(auto i: ans){
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}