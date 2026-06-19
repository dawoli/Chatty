#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
