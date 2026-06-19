#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,r[100005],vis[100005],ans;
bool fa;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
		if(r[i]>2) fa=0;
		else fa=1;
	}
	if(fa)
	{
		for(int i=1;i<=n;i++)
			if(r[i]==2) ans++;
		cout<<ans;
		return 0;
	}
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(r[j]>r[i]&&!vis[j])
			{
				vis[j]=1;
				vis[i]=2;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(vis[i]!=2) ans++;
	cout<<ans;
	return 0;
}
