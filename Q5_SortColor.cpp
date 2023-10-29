#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}

void sortColors(vector<int> &arr){
	int zeroCount=0,twoCount=arr.size()-1,i=0;
	while(i<=twoCount){
		if(arr[i]==0){
			swap(arr[i],arr[zeroCount]);
			zeroCount++;
			i++;
		}
		else if(arr[i]==2){
			swap(arr[i],arr[twoCount]);
			twoCount--;
		}
		else{
			i++;
		}
	}
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
	sortColors(arr);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}