#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n,q,f,l,phash[2500005],dh1,dh2;
struct words{
	string a,b;
	int p1,p2,hsh,dhsh1,dhsh2;
}p[200005];
string s,t;
int power(int i,int j){
	int ans = 1;
	while(j){
		if(j & 1){
			ans *= i;
			ans %= mod;
		}
		i *= i;
		i %= mod;
		j >>= 1ll;
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++){
		cin >> p[i].a >> p[i].b;
		p[i].a = ' ' + p[i].a;
		p[i].b = ' ' + p[i].b;
		p[i].p1 = p[i].p2 = p[i].hsh = p[i].dhsh1 = p[i].dhsh2 = 0;
		for(int j = 1; j < p[i].a.length(); j++){
			p[i].hsh *= 2009;
			p[i].hsh += p[i].a[j] + 1016;
			p[i].hsh %= mod;
		}
		for(int j = 1; j < p[i].a.length(); j++){
			if(p[i].a[j] != p[i].b[j]){
				p[i].p1 = j;
				break;
			}
		}
		for(int j = p[i].a.length()-1; j >= 1; j--){
			if(p[i].a[j] != p[i].b[j]){
				p[i].p2 = j;
				break;
			}
		}
		for(int j = p[i].p1; j <= p[i].p2; j++){
			p[i].dhsh1 *= 2009;
			p[i].dhsh1 += p[i].a[j] + 1016;
			p[i].dhsh1 %= mod;
		}
		for(int j = p[i].p1; j <= p[i].p2; j++){
			p[i].dhsh2 *= 2009;
			p[i].dhsh2 += p[i].b[j] + 1016;
			p[i].dhsh2 %= mod;
		}
	}

	for(int i = 0; i < q; i++){
		cin >> s >> t;
		s = ' ' + s;
		t = ' ' + t;
		if(s.length() != t.length()){
			cout << "0\n";
			continue;
		}
		dh1 = dh2 = 0;
		int ans = 0;
		phash[1] = s[1] + 1016;
		for(int j = 2; j < s.length(); j++){
			phash[j] = phash[j - 1] * 2009;
			phash[j] += s[j] + 1016;
			phash[j] %= mod;
		}
		for(int j = 1; j < s.length(); j++){
			if(s[j] != t[j]){
				f = j;
				break;
			}
		}
		for(int j = s.length() - 1; j >= f; j--){
			if(s[j] != t[j]){
				l = j;
				break;
			}
		}
		for(int j = f; j <= l; j++){
			dh1 *= 2009;
			dh1 += s[j] + 1016;
			dh1 %= mod;
		}
		for(int j = f; j <= l; j++){
			dh2 *= 2009;
			dh2 += t[j] + 1016;
			dh2 %= mod;
		}
	
		for(int j = 1; j <= n; j++){
			if(l - f >= p[j].a.length() || p[j].a.length() > s.length()){
			continue;}
			if(dh1 != p[j].dhsh1 || dh2 != p[j].dhsh2){
			continue;}
			if(f < p[j].p1 || s.length() - l < p[j].a.length() - p[j].p2){
			continue;}
			//cout << ((p[j].hsh * power(2009,f - p[j].p1 + mod))%mod) << ' ' << (phash[l - p[j].p1 + 1] - phash[f - p[j].p1] + mod)%mod << '\n';
			if(((p[j].hsh * power(2009,f - p[j].p1))%mod) == (phash[l - p[j].p1 + 1] - phash[f - p[j].p1] + mod)%mod)ans++;
		}
		cout << ans << '\n';
	}
	
	return 0;
}  
