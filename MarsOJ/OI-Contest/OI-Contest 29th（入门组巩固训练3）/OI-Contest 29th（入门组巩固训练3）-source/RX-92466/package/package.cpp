#include<bits/stdc++.h>
using namespace std;
int v[1000001],t[10001],w[10001];
int main(){
	freopen("package.in","r",stdin);
	freopen("package.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int mn=2e9;
	int tmp;
	for(int i=1;i<=m;i++){
		cin>>v[i];
		if(v[i]<mn){
			mn=v[i],tmp=i;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>t[i]>>w[i];
	}
	if(n<=m){
		cout<<v[n];
	}
	else{
		cout<<n/tmp*v[tmp]+v[n%tmp];
	}
	return 0;
}
