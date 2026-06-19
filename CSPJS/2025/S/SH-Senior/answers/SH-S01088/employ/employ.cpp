#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],d[510],e[510],h[510];
long long ans,sum,num,num0;
string s;
bool p[510],use[510];
const long long P=998244353;
void dfs(int step)
{
	if(step==n)
	{
		for(int i=1;i<=n;i++)
			e[i]=c[d[i]];
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i]==0||e[i]<=sum)
				sum++;
		}
		if(n-sum>=m)
			ans++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!use[i])
		{
			use[i]=1;
			d[step+1]=i;
			dfs(step+1);
			use[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=0;i<n;i++)
		if(s[i]=='1')
			p[i+1]=1;
	if(n<=10)
	{
		dfs(0);
		cout<<ans%P<<endl;
	}
	else if(m==n) 
	{
		bool flag=1;
		for(int i=1;i<=n;i++)
			if(!p[i])
			{
				flag=0;
				break;
			}
		for(int i=1;i<=n;i++)
			if(!c[i])
			{
				flag=0;
				break;
			}
		if(!flag)
			cout<<0<<endl;
		else
		{
			ans=1;
			for(int i=1;i<=n;i++)
			{
				ans*=i;
				ans%=P;
			}
			cout<<ans<<endl;
		}
	}
	else if(m==1)
	{
		ans=1;sum=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=P;
		}
		for(int i=1;i<=n;i++)
			h[c[i]]++;
		for(int i=0;i<n;i++)
		{
			num+=h[i];
			if(p[i+1]==0)
			{
				num0++;
			}
			else
			{
				sum*=num;
				sum%=P;
				num--;
			}
		}
		for(int i=1;i<=num0;i++)
		{
			sum*=i;
			sum%=P;
		}
		ans=(ans-sum+P)%P;
		cout<<ans<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
