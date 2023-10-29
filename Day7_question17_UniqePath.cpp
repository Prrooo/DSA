#include<bits/stdc++.h>
using namespace std;

// https://takeuforward.org/data-structure/grid-unique-paths-count-paths-from-left-top-to-the-right-bottom-of-a-matrix/

// brute force 
// we count all the possible posibility using recursion one by one 
// space complexity O(N) stack space used in recursion time complexity Exponential

// void solve(int &count,int row,int col,int i,int j){
// 	if(i==row && j==col){
// 		count++;
// 		return;
// 	}
// 	if(i+1<=row){
// 		solve(count,row,col,i+1,j);
// 	}
// 	if(j+1<=col){
// 		solve(count,row,col,i,j+1);
// 	}
// }

// int countPath(int row,int col){
// 	int count=0;
// 	solve(count,row-1,col-1,0,0);
// 	return count;
// }

// =================================================================================

// better approach using dynamic programming
// we make M*N array and initialise all of them as -1 and sort the ans we get form
// recursion in the array and we have to compute same problem that we have solve and
// store in the array then we don't call recursion call , simply use the value in the
// array 

// int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp)
// {
//     if(i==(n-1)&&j==(m-1)) return 1;
//     if(i>=n||j>=m) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     else return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);        
// }
// int uniquePaths(int m, int n) {
//     vector<vector<int>> dp(m+1,vector<int>(n+1,-1));       
//         //dp[1][1]=1;
//    int num=countPaths(0,0,m,n,dp);
//     if(m==1&&n==1)
//         return num;
//     return dp[0][0];
// }

// most optimize approach 
// If we observe examples there is a similarity in paths from start to end. 
// Each time we are taking an exactly m+n-2 number of steps to reach the end.

int uniquePaths(int n,int m){
	int N=n+m-2;
	int r=n-1;
	double res=1;
	// this is the shortcut to find the permutation of the and number
	// nCr=n!/r!(n-r)! for example n=4 r=2
	// 4!/2!2! =? 4*3/2 ; which we can calcuate by simply using for loop
	// upto r and in every loop ans=ans*(n-r+i)/i 
	for(int i=1;i<=r;i++){
		res=res*(N-r+i)/i;
	}
	return (int)res;
}

int main(){
	int n,m;
	cin>>n>>m;
	// vector<vector<int>> arr;
	// for(int i=0;i<n;i++){
	// 	vector<int> toPush;
	// 	for(int j=0;j<;j++){
	// 		int x;
	// 		cin>>x;
	// 		toPush.push_back(x);
	// 	}
	// 	arr.push_back(toPush);
	// }
	cout<<uniquePaths(n,m);
	return 0;
}
