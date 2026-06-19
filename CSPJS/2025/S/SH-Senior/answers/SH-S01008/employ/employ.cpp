#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
string s;
int c[505],cnt=0;
const int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	ans=1;
	for(int i=1;i<=n;i++)
	{
		if(c[i]<=cnt)
			cnt++;
	}	
	for(int i=1;i<=n-cnt;i++)
		ans*=i,ans%=mod;
	cout<<ans<<endl;
	return 0;
}
