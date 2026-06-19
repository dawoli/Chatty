#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a,c,k,t,x[4];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a;
	for(int i=1;i<=m;i++) cin>>c;
	for(int i=1;i<=14;i++) cin>>k;
	cin>>t;
	while(t--) cin>>x[0]>>x[1]>>x[2]>>x[3];
	return 0;
}
