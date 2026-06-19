#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,m;
string hard;
int c[501];
void input()
{
	cin>>n>>m;
	cin>>hard;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	return;
}
bool spe_a_check()
{
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		if(hard[i]!='1')
		{
			flag=false;
			break;
		}
	}
	return flag;
}
bool imp()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
			cnt++;
		}
	}
	if(cnt+m>n)
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	input();
	if(imp())
	{
		cout<<0;
		return 0;
	}
	if(spe_a_check())
	{
		long long ans=1;
		while(n--)
		{
			ans*=n;
			if(ans>=MOD)
			{
				ans%=MOD;
			}
			
		}
		cout<<ans;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			
		}
	}
	else 
	{
		
	}
	return 0;
}
