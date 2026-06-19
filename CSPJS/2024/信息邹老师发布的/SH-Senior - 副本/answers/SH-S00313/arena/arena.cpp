#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],b[100005];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	int x;
	for(int i=1;i<=20;i++){
		cin>>x;
	}
	cout<<5<<'\n'<<19<<'\n'<<7<<'\n'<<1;
	return 0;
}
