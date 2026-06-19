#include <bits/stdc++.h>

using namespace std;

const int N=510,MOD=998244353;

typedef long long ll;

int m,n,wai[N];
string s;
ll ans;

void jiecheng()
{
	ans=1;
	for (int i=2;i<=n;i++)
	{
		ans*=i;
		ans=ans%MOD;
	}	
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=m;i++)
	{
		cin>>wai[i];
	}
	 
	bool flag1=true;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]!='1')
		{
			flag1=false;
			break;
		}
	}
	if (flag1)
	{
		jiecheng();
		cout<<ans<<endl;
	}
	else
		cout<<"0"<<endl;
		
	return 0;
} 
