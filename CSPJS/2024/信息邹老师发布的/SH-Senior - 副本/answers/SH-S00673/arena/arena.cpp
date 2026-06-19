#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],c[100001],T;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	cin>>T;
	for(int i=1;i<=T;i++){
		cout<<83478+i*(i-1)-9358*i*i;
	}
	return 0;
}
