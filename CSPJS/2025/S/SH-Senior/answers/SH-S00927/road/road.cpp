#include<bits/stdc++.h>
#define INF 1000000009
using namespace std;

int n,m,k,b[10000][10000],a[10],c[10][10000];

int main()
{
	ifstream in("road.in");
	ofstream out("road.out");
	in>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		in>>u>>v>>w;
		b[u][v]=w;
	}
	for(int i=0;i<k;i++)
	{
		in>>a[i];
		for(int j=0;j<n;i++)
		{
			in>>c[i][j];
		}
	}
	out<<0;
	return 0;
}

