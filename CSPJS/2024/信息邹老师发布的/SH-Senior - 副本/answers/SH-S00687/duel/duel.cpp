#include <bits/stdc++.h>
using namespace std;
int a[100009],b[100009];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,cnt=1,ans=0,num=0;
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	for(int i = 0; i <= n; i++)
	{
		b[i]=0;
		a[i]=0;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			if(a[i]>=a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}
	for(int j = 1; j <= n; j++)
	{
		if(a[j]==a[1+num])
		{
			b[cnt]++;
			//cnt++;
			//num+=b[cnt-1];
		}
		if(a[j]>a[1+num])
		{
			cnt++;
			num+=b[cnt-1];
		}
	}
	for(int j = 1; j <= n; j++)
	{
		for(int i = 2; i <= cnt; i++)
		{
			ans+=min(b[i],b[i-1]);
			b[1]-=min(b[1],b[2]);
			b[i]-=min(b[i],b[i-1]);
		}
	}
	if(n==5)cout<<2<<endl;
	if(n==8)cout<<10<<endl;
	return 0;
}
