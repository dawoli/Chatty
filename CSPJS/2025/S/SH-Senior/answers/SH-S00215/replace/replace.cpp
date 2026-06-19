#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = b;i >= a;--i)
typedef long long ll;
const ll mod1 = 1e9+7,mod2 = 998244353;
inline ll read(){
	ll x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9')x = x * 10 + ch - '0',ch = getchar();
	return x * f;
}
#define N 200005
ll n,q,len[N],l[N][2],L[N],r[N][2],R[N],cnt,m261[N],m262[N],uL,uR,Len,ul[2],ur[2];
string s[N][2],t[2];
vector<ll> hsh1[N][2],HSH1[2],hsh2[N][2],HSH2[2];
map<pair<pair<ll,ll>,pair<ll,ll> >,int> mp;
vector<ll> dy[N];
#undef N
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read(),q = read();
	m261[0] = m262[0] = 1;
	rep(i,1,200000)m261[i] = m261[i - 1] * 26 % mod1,m262[i] = m262[i - 1] *26 % mod2;
	rep(i,1,n){
		cin >> s[i][0] >> s[i][1];
		len[i] = s[i][0].size();
		s[i][0] = " " + s[i][0];
		s[i][1] = " " + s[i][1];
		rep(j,1,len[i]){
			if(s[i][0][j] != s[i][1][j]){
				L[i] = j;
				break;
			}
		}
		per(j,1,len[i]){
			if(s[i][0][j] != s[i][1][j]){
				R[i] = j;
				break;
			}
		}
//		cout << L[i] << " " << R[i] << endl;
		rep(j,0,1){
			hsh1[i][j].push_back(0);
			hsh2[i][j].push_back(0);
			rep(k,1,len[i]){
				hsh1[i][j].push_back((hsh1[i][j][k - 1] * 26 % mod1 + s[i][0][k] - 'a') % mod1);
				hsh2[i][j].push_back((hsh2[i][j][k - 1] * 26 % mod2 + s[i][1][k] - 'a') % mod2);
			}
		}
		l[i][0] = hsh1[i][0][R[i]] - hsh1[i][0][L[i] - 1] * m261[R[i] - L[i] + 1] % mod1;
		l[i][0] = (l[i][0] % mod1 + mod1) % mod1;
		l[i][1] = hsh2[i][0][R[i]] - hsh2[i][0][L[i] - 1] * m262[R[i] - L[i] + 1] % mod2;
		l[i][1] = (l[i][1] % mod2 + mod2) % mod2;
		r[i][0] = hsh1[i][1][R[i]] - hsh1[i][1][L[i] - 1] * m261[R[i] - L[i] + 1] % mod1;
		r[i][0] = (r[i][0] % mod1 + mod1) % mod1;
		r[i][1] = hsh2[i][1][R[i]] - hsh2[i][1][L[i] - 1] * m262[R[i] - L[i] + 1] % mod2;
		r[i][1] = (r[i][1] % mod2 + mod2) % mod2;
//		cout << l[i][0] << " " << r[i][0] << " " << l[i][1] << " " << r[i][1] << endl;
		auto x = make_pair(make_pair(l[i][0],l[i][1]),make_pair(r[i][0],r[i][1]));
		if(!mp[x])mp[x] = ++cnt;
		dy[mp[x]].push_back(i);
	}
	while(q--){
		cin >> t[0] >> t[1];
		HSH1[0].clear();
		HSH1[1].clear();
		HSH2[0].clear();
		HSH2[1].clear();
		if(t[0].size() != t[1].size()){
			puts("0");
			continue;
		}
		Len = t[0].size();
		t[0] = " " + t[0];
		t[1] = " " + t[1];
		rep(j,1,Len){
			if(t[0][j] != t[1][j]){
				uL = j;
				break;
			}
		}
		per(j,1,Len){
			if(t[0][j] != t[1][j]){
				uR = j;
				break;
			}
		}
//		cout << uL << " " << uR << endl; 
		rep(j,0,1){
			HSH1[j].push_back(0);
			HSH2[j].push_back(0);
			rep(k,1,Len){
				HSH1[j].push_back((HSH1[j][k - 1] * 26 % mod1 + t[0][k] - 'a') % mod1);
				HSH2[j].push_back((HSH2[j][k - 1] * 26 % mod2 + t[1][k] - 'a') % mod2);
			}
		}
		ul[0] = HSH1[0][uR] - HSH1[0][uL - 1] * m261[uR - uL + 1] % mod1;
		ul[0] = (ul[0] % mod1 + mod1) % mod1;
		ul[1] = HSH2[0][uR] - HSH2[0][uL - 1] * m262[uR - uL + 1] % mod2;
		ul[1] = (ul[1] % mod2 + mod2) % mod2;
		ur[0] = HSH1[1][uR] - HSH1[1][uL - 1] * m261[uR - uL + 1] % mod1;
		ur[0] = (ur[0] % mod1 + mod1) % mod1;
		ur[1] = HSH2[1][uR] - HSH2[1][uL - 1] * m262[uR - uL + 1] % mod2;
		ur[1] = (ur[1] % mod2 + mod2) % mod2;
		auto x = make_pair(make_pair(ul[0],ul[1]),make_pair(ur[0],ur[1]));
//		cout << ul[0] << " " << ur[0] << " " << ul[1] << " " << ur[1] << endl;
		if(!mp[x]){
			puts("0");
		}
		else{
			ll cnt = 0;
			for(auto v : dy[mp[x]]){
//				cout << v << endl;
				if(uL < L[v] || (Len - uR) < (len[v] - R[v]))continue;
				ll Hv1 = hsh1[v][0][len[v]],Hv2 = hsh2[v][0][len[v]];
				ll qL = uL - L[v] + 1,qR = uR + len[v] - R[v];
				ll Hq1 = HSH1[0][qR] - HSH1[0][qL - 1] * m261[qR - qL + 1] % mod1;
				Hq1 = (Hq1 % mod1 + mod1) % mod1;
				ll Hq2 = HSH2[0][qR] - HSH2[0][qL - 1] * m262[qR - qL + 1] % mod2;
				Hq2 = (Hq2 % mod2 + mod2) % mod2;
				if(Hq1 == Hv1 && Hq2 == Hv2)++cnt;
			}
			cout << cnt << endl;
		}
	}
	return 0;
}

