#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define re(i, n) for(ll i = 1; i <= (n); i++)
#define rr(i, l, r) for(ll i = l; i <= r; i++)
#define pb push_back
string s; 
vector<ll> v; 
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] > '9' || s[i] < '0') continue;
		ll dig = s[i] - '0';
		v.pb(dig);
	}
	sort(v.begin(), v.end());
	for(int i = v.size() - 1; i >= 0; i--)
		cout<<v[i];
	cout<<endl; 
	return 0;
}

