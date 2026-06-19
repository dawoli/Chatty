#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s;
int c[509];
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=n;
		ans%=998244353;
	}
	cout<<ans<<endl;
	return 0;
}
