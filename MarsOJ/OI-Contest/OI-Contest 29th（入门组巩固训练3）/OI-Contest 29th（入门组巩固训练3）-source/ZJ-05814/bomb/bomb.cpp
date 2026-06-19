#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
const int dx[5]={0,1,-1,0};
const int dy[5]={1,0,0,-1};
int k;
bool b=1;
int main()
{
	int t,n,m,sum=0,ans=0;
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m;//ÐÐ ÁÐ
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
				cin>>a[j][k];
		}
		if(n==1)
		{
			for(int i=1;i<=m;i++)
				if(a[1][i]=='$') sum++;
			ans=m-1;
			cout<<sum<<" "<<ans;
			return 0;
		}
		else 
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]=='$') b=0;
			}
		}
		if(b)
		{
			sum=0;
		for(int i=1;i<=n;i++)
		{
		for(int j=1;j<=m;j++)
		{
			if(a[i+dx[i]][j]<=n&&a[i+dx[i]][j]>=1&&a[i][j+dy[i]]<=m&&a[i][j+dy[i]]>=1&&a[i+dx[i]][j+dy[i]]!='*')
			{
				i+=dx[i];j+=dy[i];k++;
			}
			if(i+dx[i]==n&&j+dy[i]==m) ans=k;
		}
		}
		cout<<sum<<" "<<ans;
	}	
}
	}
	return 0;
}
