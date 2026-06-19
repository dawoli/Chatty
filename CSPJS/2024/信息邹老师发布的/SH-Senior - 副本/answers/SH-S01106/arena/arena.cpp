#include<bits/stdc++.h>

using namespace std;

int t,n,m,k;

char d[35][100500];

int cif[35];

int a[100500],c[100500],x[100500];

int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cif[0] = 1;
	for(int i = 1;i <= 31;i++)
	{
		cif[i] = cif[i-1]*2;
	}
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i <= m;i++)
	{
		cin>>c[i];
	}
	for(int i = 1;i <= 31;i++)
	{
		if(cif[i] >= n)
		{
			k = i;
			break;
		}
	}
	for(int i = 1;i <= k;i++)
	{
		for(int j = 1;j <= cif[k-i];j++)
		{
			cin>>d[i][j];
		}
	}
	cin>>t;
	while(t--)
	{
		for(int i = 1;i <= 4;i++)
		{
			cin>>x[i];
		}
		srand(time(0));
		int onoo = rand();
		cout<<onoo<<"\n"; 
	}
	return 0;
} 
