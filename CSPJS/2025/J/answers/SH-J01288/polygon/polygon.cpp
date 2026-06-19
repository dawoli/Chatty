#include <bits/stdc++.h>
using namespace std;
bool flag[5005];
int n,ans,a[5005];
int Cob[5005][5005],Maxn=0;
const int Mod=998244353;
void dfs(int Step,bool f[])
{
	if(Step==n+1)
	{
		int sum=0,maxn=0;
		for(int i=1;i<=n;i++) 
		{
			if(f[i]==1) 
			{
				sum+=a[i];
				maxn=max(maxn,a[i]);
			}
		}
		if(sum>2*maxn) ans++;
		return;
	}
	f[Step]=0;
	dfs(Step+1,f);
	f[Step]=1;
	dfs(Step+1,f);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],Maxn=max(Maxn,a[i]);
	if(Maxn==1)
	{
		for(int i=0;i<=5001;i++) Cob[i][0]=1;
		for(int i=0;i<=5001;i++) Cob[i][i]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				Cob[i][j]=(Cob[i-1][j-1]+Cob[i-1][j])%Mod;
			}
		}
		for(int i=3;i<=n;i++) ans=(ans+Cob[n][i])%Mod;
		cout<<ans%Mod<<endl;
	}
	else
	{
		dfs(1,flag);
		cout<<ans%Mod<<endl;
	}
	return 0;
}
