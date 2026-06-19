#include<bits/stdc++.h>
using namespace std;
struct node
{
	int s,t,v;
}edg[1919810];
int fa[114514],mon[114514];
int find(int i)
{
	if(fa[i]==i)return i;
	else return fa[i]=find(fa[i]);
}
bool cmp(node x,node y)
{
	return x.v<y.v;
}
int main()
{

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&edg[i].s,&edg[i].t,&edg[i].v);
    }
	for(int i=1;i<=k;i++)
	{
		int qwqwwq;cin>>qwqwwq;
		for(int j=1;j<=n;j++)
		{
			edg[m+(i-1)*n+j].s=n+i;
			edg[m+(i-1)*n+j].t=j;
			scanf("%d",&edg[m+(i-1)*n+j].v);
		}
	}
	m+=k*n;
	n+=k;
	sort(edg+1,edg+m+1,cmp);
	long long choo=0,ans=0;
	for(int i=1;i<=m;i++)
	{
		int f=edg[i].s,e=edg[i].t,p=edg[i].v;
		if(find(f)!=find(e))
		{
			ans+=p;
			choo++;
			fa[find(f)]=find(e);
		}
		if(choo==n-1)break;
	}
	cout<<ans;
}
/*
拿到这个题目，她哭了。
哭着说：“啊！我不会，我不会，我不会！
讨厌，题目都没看你就说你不会，你是来搞笑的吧！
不过，你既然是来跟wwqk4444学算法的......
我要把你教成班级第一名。
先骗点分，
因为骗分代表自信。
*/ 
