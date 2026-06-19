#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,r=1,c=1,flg=1,a[110];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=n*m; ++i) cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1);
	for(ll i=n*m; i>=1; --i) {
		if(a[i]==k) {
			cout<<c<<" "<<r;
			return 0;
		}
		r+=flg;
		if(r>n) ++c,r=n,flg=-flg;
		if(r<1) ++c,r=1,flg=-flg;
	}
	return 0;
}
