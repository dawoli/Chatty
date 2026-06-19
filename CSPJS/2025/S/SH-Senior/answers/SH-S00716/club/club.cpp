#include<bits/stdc++.h>
#define pll pair<int,int>
#define ll long long
using namespace std;
 
int n;
const int N=1e5+10;
struct node{
	int v1,v2,v3;
}a[N];

int vis[4][N];

bool cmp1(int x,int y)
{
	int M1=min(a[x].v1-a[x].v2,a[x].v1-a[x].v3);
	int M2=min(a[y].v1-a[y].v2,a[y].v1-a[y].v3);
	return M1<M2;
}

bool cmp2(int x,int y)
{
	int M1=min(a[x].v2-a[x].v1,a[x].v2-a[x].v3);
	int M2=min(a[y].v2-a[y].v1,a[y].v2-a[y].v3);
	return M1<M2;
}

bool cmp3(int x,int y)
{
	int M1=min(a[x].v3-a[x].v2,a[x].v3-a[x].v1);
	int M2=min(a[y].v3-a[y].v2,a[y].v3-a[y].v1);
	return M1<M2;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof vis);
		cin>>n;
		ll ans=0;
		int cnt1=0;
		int cnt2=0;
		int cnt3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].v1>>a[i].v2>>a[i].v3;
		}
		for(int i=1;i<=n;i++)
		{
			int Now=max(a[i].v3,max(a[i].v1,a[i].v2));
			if(Now==a[i].v1)
			{
				vis[1][++cnt1]=i;
			}
			else if(Now==a[i].v2)
			{
				vis[2][++cnt2]=i;
			}
			else{
				vis[3][++cnt3]=i;
			}
			ans+=Now;
		}
		if(cnt1>n/2)
		{
			sort(vis[1]+1,vis[1]+cnt1+1,cmp1);
			for(int i=1;i<=cnt1-n/2;i++)
			{
				int R=vis[1][i];
				ans-=min(a[R].v1-a[R].v2,a[R].v1-a[R].v3);
			}
			cout<<ans<<'\n';
		}
		else if(cnt2>n/2)
		{
			sort(vis[2]+1,vis[2]+cnt2+1,cmp2);
			for(int i=1;i<=cnt2-n/2;i++)
			{
				int R=vis[2][i];
				ans-=min(a[R].v2-a[R].v1,a[R].v2-a[R].v3);
			}
			cout<<ans<<'\n';
		}
		else if(cnt3>n/2)
		{
			sort(vis[3]+1,vis[3]+cnt3+1,cmp3);
			for(int i=1;i<=cnt3-n/2;i++)
			{
				int R=vis[3][i];
				ans-=min(a[R].v3-a[R].v1,a[R].v3-a[R].v2);
			}
			cout<<ans<<'\n';
		}
		else{
			cout<<ans<<'\n';
		}
	}
	return 0;
}
