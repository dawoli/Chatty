#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int ans=0;
int shu[100005];
int flag[100005]={0};
void start()
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		shu[i]=0;
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>shu[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(shu[i]==shu[j]&&flag[j]==0)
			{
				ans+=shu[i];
				for(int k=j;k<=i;k++)
				{
					flag[k]=1;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		start();
	}
	return 0;
}
