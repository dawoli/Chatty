#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<cmath>
using namespace std;
int n,a,x,y,cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x>>y;
	n=x*y;
	cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		while(a>cnt) cnt=a;
	}
	cout<<cnt;
	return 0;
}
