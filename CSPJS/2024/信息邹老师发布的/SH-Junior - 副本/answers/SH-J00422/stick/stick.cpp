#include <bits/stdc++.h>
using namespace std;
int t,n,l,st[10]={6,2,5,5,4,5,6,3,7,6},num[20009];
bool dfs(int x,int m)
{
	if(x==n)return 1;
	if(7*(l-m+1)<n-x)return 0;
	for(int i=0;i<=9;i++)
	{
		if(m==1&&i==0||st[i]>n-x)continue;
		num[m]=i;
		if(dfs(x+st[i],m+1))return 1;
	}
	return 0;
}
int main()
{
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		l=(n+6)/7;
		if(dfs(0,1))
			for(int i=1;i<=l;i++)cout<<num[i];
		else cout<<-1;
		cout<<endl;
	}
	return 0;
}
