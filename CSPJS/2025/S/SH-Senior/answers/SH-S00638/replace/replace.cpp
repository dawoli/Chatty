#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5,M = 1e6 + 5,b = 131;
ll n,q;
unsigned long long p[N],h1[N],h2[N],h3[M],h4[M];
string s1[N],s2[N],t1[N],t2[N];
void input() {
	cin>>n>>q;
	for(ll i = 1;i <= n;i++) cin>>s1[i]>>s2[i];
	for(ll i = 1;i <= q;i++) cin>>t1[i]>>t2[i];
}
void solve() {
	p[0] = 1;
	for(ll i = 1;i <= 2000;i++) p[i] = p[i - 1] * b;
	for(ll i = 1;i <= n;i++) {
		for(ll j = 0;j < s1[i].size();j++) h1[i] = h1[i] * b + s1[i][j];
		for(ll j = 0;j < s2[i].size();j++) h1[i] = h1[i] * b + s2[i][j];
	}
	for(ll i = 1;i <= q;i++) {
		for(ll j = 0;j < t1[i].size();j++) h3[j] = h3[j - 1] * b + t1[i][j];
		for(ll j = 0;j < t2[i].size();j++) h4[j] = h4[j - 1] * b + t2[i][j];
		ll cnt1 = 0,cnt2 = 0;
		for(ll j = 1;j <= n;j++) {
			for(ll k = 0;k < t1[i].size();k++) {
				if(h3[k] - h3[k - s1[j].size()] * p[s1[j].size()] == h1[j]) cnt1 += 1;
			}
			for(ll k = 0;k < t2[i].size();k++) {
				if(h4[k] - h4[k - s2[j].size()] * p[s2[j].size()] == h2[j]) cnt2 += 1;
			}
		}
		cout<<cnt1 * cnt2<<'\n';
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input(); solve();
	return 0;
} 
