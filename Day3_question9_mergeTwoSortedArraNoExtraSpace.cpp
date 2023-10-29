#include<bits/stdc++.h>
using namespace std;

void printArray(vector<long long> &a,vector<long long> &b){
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}
	for(int i=0;i<b.size();i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
}

// my approach ======================= time complexety o(n*m) where n and m is 
// the size of the matrix and space complexity is O(1)

// void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a,vector<long long> &b){
// 	int n=a.size(),m=b.size();
// 	int aPoint=0,bPoint=0;
// 	while(aPoint<n && bPoint<m){
// 		if(a[aPoint]<=b[bPoint]){
// 			aPoint++;
// 		}
// 		else{
// 			swap(a[aPoint++],b[bPoint]);
// 			// bPoint=bPoint%m;
// 			for(int i=0;i<m-1;i++){
// 				if(b[i]>b[i+1]){
// 					swap(b[i],b[i+1]);
// 				}
// 				else{
// 					break;
// 				}
// 			}
// 		}
// 	}
// }

// another approach using gap method ==============
// we take the gap between the size of two matrix and set the pointer according to the 
// gap and the traverse the martix assuming both to be single matrix while the right pointer 
// goes out of the matrix then we reduce the size of the gap by half 
// while gap is not equal to 1 
// and check if left pointer is greater than right pointer if yes the sway them 
// else continue 

void swapIfGreater(vector<long long> &arr1,vector<long long> &arr2, int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &arr1,vector<long long> &arr2){
	int n=arr1.size();
	int m=arr2.size();
	int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<long long> a;
	vector<long long> b;
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		a.push_back(x);
	}
	for(int i=0;i<m;i++){
		long long x;
		cin>>x;
		b.push_back(x);
	}
	mergeTwoSortedArraysWithoutExtraSpace(a,b);
	printArray(a,b);
	return 0;
}