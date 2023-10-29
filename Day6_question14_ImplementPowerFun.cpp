#include<bits/stdc++.h>
using namespace std;

// Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).

// Brute Force approach TIME COMPLEXITY O(N) AND SPACE COMPLEXITY O(1)	 =============
// in this we simply traverse form 1 to n and multiply the ans with the x n times 
// and if the n is -ve then we divide the ans to 1 (1/ans) 
// ans^-3 = 1/ans^3;

// double power(double x,double n){
// 	double ans=1.0;
// 	for(int i=0;i<abs(n);i++){
// 		ans=ans*x;
// 	}
// 	if(n<0){
// 		return 1/ans;
// 	}
// 	return ans;
// }

// =============================

// optimise approach time compleixty O(logN) and space complexity O(1)  
// we compute until the power is greater than zero 
// if the power is even then we half the power (n/2) and multiple x*x
// example n is the power = 4
// and x is the number then x^4=(x*x)^2 which is (X^2)^2
// and if n is odd we multiply the ans with ans*(x)^(n-1)

double power(int x,int n){
	double ans=1;
	int nn=abs(n);
	while(nn>0){
		if(nn%2){ // for odd ===========
			ans=ans*x;
			nn--;
		}
		else{
			x=x*x;
			nn=nn/2;
		}
	}
	if(n<0){
		return 1/ans;
	}
	return ans;
}

int main(){
	double x,n;
	cin>>x>>n;
	cout<<power(x,n);
	return 0;
}