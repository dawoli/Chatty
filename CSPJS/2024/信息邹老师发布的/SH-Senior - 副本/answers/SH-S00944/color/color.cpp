#include<bits/stdc++.h>
using namespace std;
int T,n,a[200010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;int ct=0;
		for(int i=1;i<=n;i++) cin>>a[i],ct+=a[i];
		cout<<ct/2<<endl;
	}
}
