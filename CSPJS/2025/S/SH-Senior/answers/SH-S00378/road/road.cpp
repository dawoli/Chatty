#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000100],v[1000100],w[1000100],a[10100][10100],c[100],minn=9999999,p;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		p=c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			p+=a[i][j];
		}
		if(p<minn) minn=p;
	}
	cout<<minn<<endl;
	return 0;
}
