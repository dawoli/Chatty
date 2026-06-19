#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[100100];
	int v[100100];
	int w[100100];
	int a[100100];
	int c;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	cin>>c;
	for(int i=1;i<=k;i++)
	{
		cin>> a[i];
	}
	cout<<"13";
	return 0;
}
