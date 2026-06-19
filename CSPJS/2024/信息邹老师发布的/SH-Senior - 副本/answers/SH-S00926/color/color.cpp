#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[200005];
unsigned long long c;
bool color[200005];
unsigned long long ans[15];
void dfs(int k,int end,int TT)
{
	if(k==end+1)
	{
		for(int i=1;i<=end;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(color[i]==color[j])
				{
					if(a[i]==a[j])
					{
						c+=a[i];
					}
					break;
				}
			}
		}
		ans[TT]=max(ans[TT],c);
		return;
	}
	color[k]=0;
	dfs(k+1,end,TT);
	color[k]=1;
	dfs(k+1,end,TT);
	color[k]=0;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int ii=1;ii<=T;ii++)
	{
		cin>>n;
		for(int i=0;i<=n+3;i++)
		{
			a[i]=0;
			color[i]=0;
			c=0;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		dfs(1,n,ii);
	}
	for(int i=1;i<=T;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
