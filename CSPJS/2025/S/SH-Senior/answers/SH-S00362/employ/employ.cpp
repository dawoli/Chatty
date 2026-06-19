#include<bits/stdc++.h>
#define MAXN 510
#define mod 998244353
using namespace std;

char t;
long long n,m,i,tmp,Sc,ans,s[MAXN],c[MAXN],fac[MAXN],flag,book[15],a[15];

void dfs(int k)
{
	if(k == n)
	{
		int gone = 0,tot = 0;
		for(int i = 1;i <= n;i++)
		{
			if(s[i] == 0 || gone >= c[a[i]])gone++;
			else tot++;
		}
		if(tot >= m)ans++;
		return;
	}
	for(i = 1;i <= n;i++)
	{
		if(book[i] = 0)
		{
			book[i] = 1;
			a[k] = i;
			dfs(k+1);
			book[i] = 0;
			a[k] = 0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0] = 1;
	for(i = 1;i <= 501;i++)fac[i] = fac[i-1]*i%mod;
	cin>>n>>m;
	for(i = 1;i <= n;i++)
	{
		cin>>t;
		s[i] = t-'0';
		tmp += s[i];
	}
	for(i = 1;i <= n;i++)
	{
		cin>>c[i];
		if(c[i] == 0)flag = 1;
		Sc += c[i];
	}
	if(m == n)   //P15
	{
		if(tmp != n)cout<<0;
		else if(flag)cout<<0;
		else cout<<fac[n];
		fclose(stdin),fclose(stdout);
		return 0;
	}
	dfs(1);
	cout<<ans;
	fclose(stdin),fclose(stdout);
	return 0;
}
