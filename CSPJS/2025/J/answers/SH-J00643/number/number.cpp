#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<cmath>
using namespace std;
int n,a,x,y,cnt,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	cnt=n;
	if(n=0){
		cout<<0;
		return 0;
	}
	while(cnt!=0){
		cout<<cnt%10;
		cnt=cnt/10;
	}
	return 0;
}
