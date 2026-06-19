#include<bits/stdc++.h>
using namespace std;
int n,x,y,ans,a[1000005],vis[1000005],c,d,e,f;
bool u[1000005];
bool cmp(int a,int b)	{
	return a<b;
}
int check(int a)	{
	bool flag=0;
	for(int i=a+1;i<=100000;i++)	{
		if(vis[i]!=0)	{
			x=i;
			flag=1;
			break;
		}
	}
	if(flag==1)	return x;
	else return 0;
}
int main()	{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++)	{
		cin>>a[i];
		vis[a[i]]++;
	}
	sort(a+1,a+n+1,cmp);
	e=check(0),f=check(e);
	for(int i=1;i<=100000;i++)	{
		if(check(i)==0)	{			
			break;
		}
		else
		{
			e=check(0);
			f=check(e);
			if(c==e&&d==f)	break;
			if(vis[f]>vis[e])	{
				ans-=vis[e];
				vis[e]=0;
			}
			if(vis[f]<=vis[e])	{
				ans-=vis[f];
				vis[f]-=vis[e];
			}
			c=e,d=f;
		}
	}
	cout<<ans;
	return 0; 
}
