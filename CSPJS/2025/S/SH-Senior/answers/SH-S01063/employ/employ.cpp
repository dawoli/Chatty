#include <bits/stdc++.h>
using namespace std;
unsigned long long n,m,c[501],cnt,ans,ans2=1,p=998244353;
string s;
bool f=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
		if(c[i]==0) cnt++;
		if(s[i-1]==0) f=0;
	}
	//cout << n-cnt << endl;
	if(f)
	{
		if(n-cnt<m)
		{
			cout << 0;
			return 0;
		}
		for(int k=m;k<n-cnt;k++)
		{
			unsigned long long xx=1;
			for(int i=n-cnt;i>k;i--)
			{
				//cout << i << endl;
				unsigned long long x=xx;
				for(int j=1;j<i;j++) xx=(xx+x)%p;
			}
			ans=(ans+xx)%p;
		}
		for(int i=1;i<=n-cnt;i++)
		{
			unsigned long long x=ans2;
			for(int j=1;j<i;j++) ans2=(ans2+x)%p;
		}
		cout << (ans+ans2)%p;
		return 0;
	}
} 
