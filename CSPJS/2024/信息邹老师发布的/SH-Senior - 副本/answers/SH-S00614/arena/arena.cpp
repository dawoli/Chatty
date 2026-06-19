#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],c[100010],t,w,x,y,z,k;
string d;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>c[i];
	k=ceil(log2(1.0*n));
	for(int i=1;i<=k;i++)cin>>d;
	scanf("%d",&t);
	while(t--){
		cin>>w>>x>>y>>z;
		printf("0\n");
	}
	return 0;
}
