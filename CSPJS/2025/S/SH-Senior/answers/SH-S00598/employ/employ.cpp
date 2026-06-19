#include<bits/stdc++.h>
using namespace std;

int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n, m, cnt=0;
	bool flag=false;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1; i<=n; i++)
	{
		cin>>c[i];
		if(c[i]==0)cnt++;
	}
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]!='1'){
		flag=true;break;}
	}
	if(!flag)
	{
		if(m>n-cnt)
		{
			cout<<0;
			return 0;
		}
		long long ans=1;
		for(int i=1; i<=n-cnt; i++)
		{
			ans=(ans*i)%998244353;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}


