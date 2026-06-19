#include<bits/stdc++.h>
using namespace std;
long long p=998244353;
long long n,m,a[501],s[501],ans=0,b[501];
string ss;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>ss;
	for(int i=1;i<=n;i++) s[i]=int(ss[i-1]-'0');
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=10)
	{
		for(int i=1;i<=n;i++) b[i]=i;
		do
		{
			//for(int i=1;i<=n;i++) cout<<a[b[i]]<<" ";
			//cout<<endl; 
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i]==0) cnt++;
				else
				{
					if(cnt>=a[b[i]]) cnt++;
				}
			}
			if(n-cnt>=m) ans++;
			//cout<<ans<<endl;
		}
		while(next_permutation(b+1,b+n+1));
	}
	else
	{
		ans=1;
		for(int i=2;i<=n;i++) ans=ans*i%p;
	}
	cout<<ans%p<<endl;
	return 0;
}
