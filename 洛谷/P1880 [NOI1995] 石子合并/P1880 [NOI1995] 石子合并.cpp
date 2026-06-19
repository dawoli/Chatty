#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=201;
int n,a[maxn],fi[maxn][maxn],fx[maxn][maxn],w[maxn][maxn],ansi=INT_MAX,ansx=INT_MIN;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int i=1;i<=2*n;i++)
		fx[i][i]=fi[i][i]=0;
	for(int i=1;i<=2*n;i++)
		for(int j=i;j<=2*n;j++)
			w[i][j]=w[i][j-1]+a[j];
	for(int L=2;L<=n;L++)
		for(int i=1;i+L-1<=2*n;i++)
		{
			int j=i+L-1,&fiij=fi[i][j],&fxij=fx[i][j];
			fiij=INT_MAX;
			fxij=INT_MIN;
			for(int k=i;k<j;k++)
				fiij=min(fiij,fi[i][k]+fi[k+1][j]+w[i][j]);
			for(int k=i;k<j;k++)
				fxij=max(fxij,fx[i][k]+fx[k+1][j]+w[i][j]);
		}
	for(int i=1;i<=n;i++)
	{
		int j=i+n-1;
		ansi=min(ansi,fi[i][j]);
		ansx=max(ansx,fx[i][j]);
	}
	cout<<ansi<<endl<<ansx<<endl;
	return 0;
}