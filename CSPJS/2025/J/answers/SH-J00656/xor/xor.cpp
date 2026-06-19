#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int f[N*N];
int a[N][N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	int sum=0;
	int minn=0;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		a[i][i]=f[i];
		if(a[i][i]==m)
		{
			sum++;
			maxn=i;
			minn=i;	
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			a[i][j]=int(a[i][j-1]^f[j]);
			if(a[i][j]==m&&minn>j||maxn<i)
			{
				sum++;
				minn=min(minn,i);
				maxn=max(maxn,j);	
			}
		}
	}
	cout<<sum;
	return 0;
}
