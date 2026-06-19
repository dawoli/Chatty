#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
const int mod=998244353;
int n,m,c[501],a[501],flag[501],yiluqu=0,weiluqu=0,ans,tiaojian[501];
string s;
void solve(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			flag[i]=1;
			if(weiluqu<c[i]&&a[x]==1)
			{
				yiluqu++;
				tiaojian[x]=1;
			}
			else 
			{
				weiluqu++;
				tiaojian[x]=0;
			}
			solve(yiluqu+weiluqu+1);
			if(tiaojian[x]==1)
			{
				yiluqu--;
			}
			else 
			{
				weiluqu--;
			}
			flag[i]=0;
		}
	}
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			f=0;
			break;
		}
	}
	if(f==1&&yiluqu>=m)
	{
		ans++;
		ans=ans%mod;
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++)
	{
		a[i+1]=s[i]-48;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	solve(1);
	cout<<ans;
	return 0;
}
