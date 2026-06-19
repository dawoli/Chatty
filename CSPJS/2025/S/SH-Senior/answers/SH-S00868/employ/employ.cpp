#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m;
char pa[N];
int s[N];
int c[N];
long long t=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int che=1,co=0,cone=0;
	for(int i=1;i<=n;i++)
	{
		cin>>pa[i];
		s[i]=pa[i]-'0';
		if(s[i]==0) che=0;
		cone+=(s[i]==1);
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>c[i];
		if(c[i]==0) co++;
	}
	if(n==m)
	{
		if(che==0||co!=0)
		{
			cout<<0;
			return 0;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				t*=i;
				if(t>998244353) t%=998244353;
			}
			cout<<t;
			return 0;
		}
	}
	if(che==1)
	{
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++)
		{
			t*=i;
			if(t>998244353) t%=998244353;
		}
		cout<<t;
		return 0;
	}
	if(n-co<m||cone<m)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		t*=i;
		if(t>998244353) t%=998244353;
	}
	cout<<t;
	return 0;
}
