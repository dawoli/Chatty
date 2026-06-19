#include<bits/stdc++.h>
using namespace std;
int n,a[5001],cnt=0;
int sum=0,maxx=0;
void dfs(int t,int des)
{
	int tmp=maxx;
	if(t==des+1)
	{
		if(sum>2*a[maxx])
		{
			cnt=(cnt+1)%998244353;
		}
		return;
	}
	for(int i=maxx+1;i<=n-(des-t);i++)
	{
		maxx=i;
		sum+=a[i];
		dfs(t+1,des);
		sum-=a[i];
		maxx=tmp;
	}
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		dfs(1,i);
	}
	cout<<cnt<<endl;
	return 0;
}
