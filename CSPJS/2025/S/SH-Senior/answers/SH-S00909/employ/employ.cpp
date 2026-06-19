#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int n,m;
string s;
int c[586],cnt,ans = 1;
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1; i <=n; ++i){
		cin>>c[i];
		if(c[i]==0)cnt++;
	}
	if(n-cnt <m)cout<<0<<endl;
	else{
		for(int i = 1; i <=n; ++i){
			ans*=i;
			ans %=mod;
		}
		cout<<ans<<endl;
	}

	return 0;
}

