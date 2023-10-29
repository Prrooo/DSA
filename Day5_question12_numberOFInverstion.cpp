// https://www.codingninjas.com/studio/problems/number-of-inversions_6840276?leftPanelTab=1

// for notes and video lecture =================
// https://takeuforward.org/data-structure/count-inversions-in-an-array/

#include<bits/stdc++.h>
using namespace std;

// question -> There is an integer arr of size n
// we have to find the number of inversion in the array 
// inversion is which who satisify the following propertiy
// i<j && arr[i]>arr[j]

// bruteformce solution 
// time complexity O(n^2) space complexity O(1)
// check for number of inversion for each element 

// int numberOfInversions(vector<int> &arr,int n){
// 	int inversion=0;
// 	for(int i=0;i<n;i++){
// 		for(int j=i+1;j<n;j++){
// 			if(arr[i]>arr[j]){
// 				inversion++;
// 			}
// 		}
// 	}
// 	return inversion;
// }

// second Aproach is using merge Sort in this 
// as we sort the array we will check if the element in the left of the array
// is grater than the element in the right of the array the all the element 
// next to the element in the left array is also greater than the element in the 
// right of the array so we can add the count of all the element to the count 
// next to the element in the left array including that element also 



void mergeArray(vector<int> &arr,int &count,int left,int mid,int right){
	int leftIndex=mid-left+1;
	int rightIndex=right-mid;
	int leftArray[leftIndex];
	int rightArray[rightIndex];
	for(int i=0;i<leftIndex;i++){
		leftArray[i]=arr[left+i];
	}
	for(int i=0;i<rightIndex;i++){
		rightArray[i]=arr[mid+1+i];
	}
	int pointLeft=0,pointRight=0,curr=left;
	while(pointLeft<leftIndex && pointRight<rightIndex){
		if(leftArray[pointLeft]<=rightArray[pointRight]){
			arr[curr++]=leftArray[pointLeft++];
		}
		else{
			// imp line =====================
			// here we add the count 
			count+=leftIndex-pointLeft;
			// =====================
			arr[curr++]=rightArray[pointRight++];
		}
	}
	while(pointLeft<leftIndex){
		// count+=leftIndex-pointLeft;
		arr[curr++]=leftArray[pointLeft++];
	}
	while(pointRight<rightIndex){
		arr[curr++]=rightArray[pointRight++];	
	}
}

void mergeSortSolve(vector<int> &arr,int &count,int left,int right){
	if(left>=right){
		return;
	}
	int mid=(left+right)/2;
	mergeSortSolve(arr,count,left,mid);
	mergeSortSolve(arr,count,mid+1,right);
	mergeArray(arr,count,left,mid,right);
}

int numberOfInversions(vector<int> &arr,int n){
	int count=0;
	mergeSortSolve(arr,count,0,n-1);
	return count;
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
	cout<<numberOfInversions(arr,n);
	// int count=0;
	// mergeSortSolve(arr,count,0,n-1);
	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;
	return 0;
}