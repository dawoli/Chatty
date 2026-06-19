#include<bits/stdc++.h>
using namespace std;
struct node
{
	int w,id;
}num[100010];
int T,n,a[100010][4],t[4],ans,maxn,vis[100010];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(t,0,sizeof(t));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			maxn=max({a[i][1],a[i][2],a[i][3]});
			num[i].id=i;
			ans+=maxn;
			if(maxn==a[i][1]) t[1]++,num[i].w=min(maxn-a[i][2],maxn-a[i][3]),vis[i]=1;
			else if(maxn==a[i][2]) t[2]++,num[i].w=min(maxn-a[i][1],maxn-a[i][3]),vis[i]=2;
			else t[3]++,num[i].w=min(maxn-a[i][2],maxn-a[i][3]),vis[i]=3;
		}
		if(t[1]>n/2)
		{
			sort(num+1,num+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(t[1]<=n/2) break;
				if(vis[num[i].id]==1)
				{
					ans-=num[i].w;
					if(num[i].w==maxn-a[num[i].id][2]) vis[num[i].id]=2,t[1]--,t[2]++;
					else vis[num[i].id]=3,t[1]--,t[3]++;
				}
			}
			if(t[2]>n/2)
			{
				for(int i=1;i<=n;i++) num[i]={a[i][2]-a[i][3],i};
				sort(num+1,num+n+1,cmp);
				for(int i=1;i<=n;i++)
				{
					if(t[2]<=n/2) break;
					if(vis[num[i].id]==2) ans-=num[i].w,vis[num[i].id]=3,t[2]--,t[3]++;
				}
			}
			if(t[3]>n/2)
			{
				for(int i=1;i<=n;i++) num[i]={a[i][3]-a[i][2],i};
				sort(num+1,num+n+1,cmp);
				for(int i=1;i<=n;i++)
				{
					if(t[2]<=n/2) break;
					if(vis[num[i].id]==2) ans-=num[i].w,vis[num[i].id]=2,t[3]--,t[2]++;
				}
			}
		}
		else if(t[2]>n/2)
		{
			sort(num+1,num+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(t[2]<=n/2) break;
				if(vis[num[i].id]==2)
				{
					ans-=num[i].w;
					if(num[i].w==maxn-a[num[i].id][1]) vis[num[i].id]=1,t[2]--,t[1]++;
					else vis[num[i].id]=3,t[2]--,t[3]++;
				}
			}
			if(t[1]>n/2)
			{
				for(int i=1;i<=n;i++) num[i]={a[i][1]-a[i][3],i};
				sort(num+1,num+n+1,cmp);
				for(int i=1;i<=n;i++)
				{
					if(t[1]<=n/2) break;
					if(vis[num[i].id]==1) ans-=num[i].w,vis[num[i].id]=3,t[1]--,t[3]++;
				}
			}
			if(t[3]>n/2)
			{
				for(int i=1;i<=n;i++) num[i]={a[i][3]-a[i][1],i};
				sort(num+1,num+n+1,cmp);
				for(int i=1;i<=n;i++)
				{
					if(t[3]<=n/2) break;
					if(vis[num[i].id]==3) ans-=num[i].w,vis[num[i].id]=1,t[3]--,t[1]++;
				}
			}
		}
		else
		{
			sort(num+1,num+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(t[3]<=n/2) break;
				if(vis[num[i].id]==3)
				{
					ans-=num[i].w;
					if(num[i].w==maxn-a[num[i].id][2]) vis[num[i].id]=2,t[3]--,t[2]++;
					else vis[num[i].id]=1,t[3]--,t[1]++;
				}
			}
			if(t[2]>n/2)
			{
				for(int i=1;i<=n;i++) num[i]={a[i][2]-a[i][1],i};
				sort(num+1,num+n+1,cmp);
				for(int i=1;i<=n;i++)
				{
					if(t[2]<=n/2) break;
					if(vis[num[i].id]==2) ans-=num[i].w,vis[num[i].id]=1,t[2]--,t[1]++;
				}
			}
			if(t[1]>n/2)
			{
				for(int i=1;i<=n;i++) num[i]={a[i][1]-a[i][2],i};
				sort(num+1,num+n+1,cmp);
				for(int i=1;i<=n;i++)
				{
					if(t[1]<=n/2) break;
					if(vis[num[i].id]==1) ans-=num[i].w,vis[num[i].id]=2,t[1]--,t[2]++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
