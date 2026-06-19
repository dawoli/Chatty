#include<bits/stdc++.h>
using namespace std;
int n,ma;
int a[100001],b[100001];
int count(int n)
{
	int t=0;
	for(int i=n;i>=2;i--)
		for(int j=i-1;j>=1;j--)
		{
			if(b[i]==b[j])
			{
				if(a[i]==a[j]) t+=a[i];
				break;
			}
		}
	return t;
}
void dfs(int i,int n)
{
	for(int j=0;j<=1;j++)
	{
		b[i]=j;
		if(i==n)
		{ 
			ma=max(count(n),ma);
			if(j==1) return;
		}
		else dfs(i+1,n);
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	for(T-=1;T>=0;T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		dfs(1,n);
		cout<<ma<<endl;
	}
	return 0;
}
