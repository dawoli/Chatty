#include<bits/stdc++.h>
#define popipa 5
#define mygo 100050
using namespace std;
int n,m,k,T;
int d[20][mygo];
int aa[mygo],a[mygo],c[mygo];
int x[popipa];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",aa[i]);
	for(int i=1;i<=m;i++)scanf("%d",c[i]);
	int roselia=1;
	while(roselia<n)roselia*=2;
	k=roselia-n;
	string s;
	for(int i=1;i<=k;i++)
	{
		cin>>s;
		for(int j=1;j<=s.length();j++)d[i][j]=s[j-1];
	}
	scanf("%d",&T);
	while(T--)
	{
		int ans[mygo];
		scanf("%d%d%d%d",&x[0],&x[1],&x[2],&x[3]);
		for(int i=1;i<=n;i++)
		{
			a[i]=aa[i]^x[i%4];
		}
		for(int i=1;i<=m;i++)
		{
			while(roselia<n)roselia*=2;
			k=roselia-n;
			ans[i]=k*(roselia+n)/2;
		}
		int outp=ans[1];
		for(int i=2;i<=m;i++)outp=outp^ans[i];
		printf("%d\n",outp);
	}
	return 0;
 } 
