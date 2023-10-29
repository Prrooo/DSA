// https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers/
#include<bits/stdc++.h>
using namespace std;

// Q> Given an array of N + 1 size, where each element is between 1 and N.
// Assuming there is only one duplicate number, your task is to 
// find the duplicate number.

// Solution ================================================


// brute force approach 
// we store the count of all the element in the array and 
// return the element whose count is greater than 1 

// time complexity O(n) and space complexity (N+1) 

// int findDuplicate(vector<int> &arr){
// 	int n=arr.size();
// 	int count[n+1]={0};
// 	for(int i=0;i<n;i++){
// 		count[arr[i]]++;
// 	}
// 	for(int i=1;i<n+1;i++){
// 		if(count[i]>1){
// 			return count[i];
// 		}
// 	}
// }

// another approch
// Sort the array. After that, if there is any duplicate number they will be adjacent.
// So we simply have to check if arr[i]==arr[i+1] and
// if it is true,arr[i] is the duplicate number.

// int findDuplicate(vector < int > & arr) {
//   int n = arr.size();
//   sort(arr.begin(), arr.end());
//   for (int i = 0; i < n - 1; i++) {
//     if (arr[i] == arr[i + 1]) {
//       return arr[i];
//     }
//   }
// }

// another approach linked list cycle method 
// time complexity O(N) and space complexity O(1);

// we take two pointer slow and fast slow will move one step and fast will take
// 2 steps if both poiter meetes then there is a duplicate in the array
// then we will move the fast to starting of the array and move 1 step
// then point where both pointer will meet again is the duplicate value 

int findDuplicate(vector<int> &arr){
	int slow=arr[0];
	int fast=arr[0];
	do
		{
			slow=arr[slow];
			fast=arr[arr[fast]];
		} while (slow!=fast);
	fast=arr[0];
	while(fast!=slow){
		slow=arr[slow];
		fast=arr[fast];
	}
	return slow;
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
	cout<<findDuplicate(arr);	
	return 0;
}