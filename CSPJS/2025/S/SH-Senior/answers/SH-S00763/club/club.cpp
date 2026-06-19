#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(ll i=a;i<=b;i++)
#define rrep(i, a, b) for(ll i=a;i>=b;i--)
ll t;
ll n;
vector <ll> ca1, ca2, ca3;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		ca1.clear();ca2.clear();ca3.clear();
		ll ans=0;
		rep(i, 1, n){
			ll a1, a2, a3;cin >> a1 >> a2 >> a3;
			if(a1>=a2&&a1>=a3){
				ca1.emplace_back(min(a1-a2, a1-a3));ans+=a1;
			}else if(a2>=a1&&a2>=a3){
				ca2.emplace_back(min(a2-a1, a2-a3));ans+=a2;
			}else if(a3>=a1&&a3>=a2){
				ca3.emplace_back(min(a3-a1, a3-a2));ans+=a3;
			}
		}
//		cout << ca1.size() << ' ' << ca2.size() << ' ' << ca3.size() << endl;
		if(ca1.size()>n/2){
			ll c=ca1.size()-n/2;
//			cout << c << endl;
			sort(ca1.begin(), ca1.end());
			rep(i, 0, c-1){
				ans-=ca1[i];
			}
		}
		if(ca2.size()>n/2){
			ll c=ca2.size()-n/2;
//			cout << c << endl;
			sort(ca2.begin(), ca2.end());
			rep(i, 0, c-1){
				ans-=ca2[i];
			}
		}
		if(ca3.size()>n/2){
			ll c=ca3.size()-n/2;
//			cout << c << endl;
			sort(ca3.begin(), ca3.end());
			rep(i, 0, c-1){
				ans-=ca3[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
