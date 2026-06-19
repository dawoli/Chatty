#include<bits/stdc++.h>
using namespace std;
int n,a[3],maxa=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cin>>a[0]>>a[1];
		cout<<0;
	}else if(n==3){
		cin>>a[0]>>a[1]>>a[2];
		maxa=max(max(a[0],a[1]),a[2]);
		if(a[0]+a[1]+a[2]>maxa*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
}
