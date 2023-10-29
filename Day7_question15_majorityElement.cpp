// question link
// https://www.codingninjas.com/studio/problems/majority-element_6783241?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTab=0

// for notes
// https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/

#include<bits/stdc++.h>
using namespace std;

// brute force 
// Use a hashmap and store as (key, value) pairs. (Can also use frequency array based on the size of nums) 
// Here the key will be the element of the array and the value will be the number of times it occurs. 
// Traverse the array and update the value of the key. Simultaneously check if the value is greater than the floor of N/2. 
// If yes, return the key 
// Else iterate forward.

// optimse aproach 
// we sort the array and the element which has more apperance will always be at the middle 
// of the sorted array 

// int majorityElement(vector<int> &arr){
// 	sort(arr.begin(),arr.end());
// 	return arr[arr.size()/2];
// }

// MOST optimise aproach 
// the element which has more apprerance will have count of greater than the rest of 
// the element 
// the we simipily traverse the array and if we found same element then count++
// we new element is found and count==0 the change element to the curr element  

int majorityElement(vector<int> &arr){
	int count=0;
	int currEle=arr[0];
	for(int i=0;i<arr.size();i++){
		if(arr[i]==currEle && count>0){
			count++;			
		}
		else if(arr[i]!=currEle && count>0){
			count--;
		}
		else if(arr[i]!=currEle && count==0){
			currEle=arr[i];
			count++;
		}
	}
	return currEle;
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
	cout<<majorityElement(arr);
	return 0;
}