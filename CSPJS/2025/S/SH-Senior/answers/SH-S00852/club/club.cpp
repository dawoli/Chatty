#include <bits/stdc++.h>
using namespace std;
#define N 100020
int v[N][3],n,ans;
int s[N];
void dfs(int u,int a,int b,int c,int cnta,int cntb,int cntc)
{
	if(cnta>n/2||cntb>n/2||cntc>n/2) return;
	if(a+b+c+s[n]-s[u-1]<ans) return;
	if(u>n)
	{
		ans=max(ans,a+b+c);
		return;
	}
	dfs(u+1,a+v[u][0],b,c,cnta+1,cntb,cntc);
	dfs(u+1,a,b+v[u][1],c,cnta,cntb+1,cntc);
	dfs(u+1,a,b,c+v[u][2],cnta,cntb,cntc+1);
}
bool checkA()
{
	for(int i=1;i<=n;i++)
	{
		if(v[i][2]!=0||v[i][1]!=0) return 0;
	}
	return 1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			cin>>v[i][0]>>v[i][1]>>v[i][2];
			s[i]=s[i-1]+max(v[i][0],max(v[i][1],v[i][2])); 
		}
		if(n<=50) dfs(1,0,0,0,0,0,0);
		else
		{
			if(checkA())
			{
				for(int i=1;i<=n;i++) s[i]=v[i][0];
				sort(s+1,s+1+n);
				for(int i=1;i<=n/2;i++) ans+=s[i];
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
