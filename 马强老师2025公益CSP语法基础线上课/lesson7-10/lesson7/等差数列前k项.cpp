#include<iostream>
#include<algorithm> 
#include<cmath>
#include<stdio.h>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int k,p;
	cin>>k>>p;
	int n=1;
	for(int i=1;i<=k;i++){
		cout<<n<<' ';
		n=n+p;
	}
	return 0;
}
