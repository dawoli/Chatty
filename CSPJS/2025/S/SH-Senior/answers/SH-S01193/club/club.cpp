#include <bits/stdc++.h>
using namespace std;
int t,n,arr[100005][5],ai[5],ans;
void dfs(int m,int anss)
{
	if(m==n+1)
	{
		ans=max(anss,ans);
		return ;
	}
	for(int i = m;i<=n;i++)
	{
		for(int j = 1;j<=3;j++)
		{
			ai[j]++;
			if(ai[j]>n/2)
			{
				ai[j]--;
				continue;
			}
			dfs(i+1,anss+arr[i][j]);
			ai[j]--;
		}
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(ai,0,sizeof ai);
		cin>>n;
		for(int i = 1;i<=n;i++)
		{
			cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
