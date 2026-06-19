#include<bits/stdc++.h>
using namespace std;
int t,n,ans,c,d,mina=0x3f3f3f3f,a[8]={-1,-1,1,7,4,2,6,8};
void dfs(int k,int j)
{
	if(k==0)
	{
		if(ans>=pow(10,c-1)&&ans<pow(10,c))
		{
			mina=min(mina,ans);
		}
		ans=0;
		return;
	}
	if(k==c)
	{
		a[6]=6;
	}
	else
	{
		a[6]=0;
	}
	for(int i=j;i<=7;i++)
	{
		ans+=a[i]*pow(10,k-1);
		n-=i;
		dfs(k-1,7+n-(k-1)*7);
		if(c==k)
		{
			ans=0;
		}
		n+=i;
	}
	return;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(n<=7)
		{
			cout<<a[n]<<endl;
			continue;
		}
		else
		{
			c=ceil(n/7.0);
			d=n-(c-1)*7;
			dfs(c,d);
		}
		cout<<mina<<endl;
	}
	return 0;
}
