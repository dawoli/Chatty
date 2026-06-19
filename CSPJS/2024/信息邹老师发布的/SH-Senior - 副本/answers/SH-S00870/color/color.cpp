#include<bits/stdc++.h>
using namespace std;
int a[1000005],ans,n;
bool c[100005];
void dfs(int step)
{
	if(step==n+1)
	{
		int sum=0;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--)
			{
				if(c[j]==c[i])
				{
					if(a[j]==a[i])
					sum+=a[i];
					break;
				}
			}
		}
		ans=max(ans,sum);
		return;
	}
	c[step]=0;
	dfs(step+1);
	c[step]=0;
	c[step]=1;
	dfs(step+1);
	c[step]=0;
	
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		dfs(1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}

