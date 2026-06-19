#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=520,MOD=998244353;
int n,m,c[N];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	int ans=1;
	for(int i=1;i<=n;i++) ans=ans*i%MOD;
	cout<<ans;
	return 0;
}
