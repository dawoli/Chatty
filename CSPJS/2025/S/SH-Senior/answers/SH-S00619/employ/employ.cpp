#include<bits/stdc++.h>
using namespace std;
int ans;
string aa;
int b[1000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	ans=1;
	cin>>n>>m;
	cin>>aa;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=n;i>=1;i--)
	{
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
