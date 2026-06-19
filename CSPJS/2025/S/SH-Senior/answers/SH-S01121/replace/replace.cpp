#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int hs[N][2], pre[40], n, q;
string s1[N], s2[N];
long long ht[2];

int fr() {
	int x = 0, w = 1;char c = getchar();
	while(c < '0' || c > '9'){if(c == '-'){w = -1;} c = getchar();}
	while(c >= '0' && c <= '9'){x = x * 10 + c - '0'; c = getchar();}
	return x * w;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = fr();q = fr();
	pre[0] = 1;
	for(int i = 1;i <= 31;i++) pre[i] = pre[i - 1] * 2 % mod;
	for(int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1;i <= n;i++) {
		int sz = s1[i].size();
		for(int j = 0;j < sz;j++) {
			hs[i][0] = (hs[i][0] + pre[s1[i][j] - 'a'])%mod;
		}
		sz = s2[i].size();
		for(int j = 0;j < sz;j++) {
			hs[i][1] = (hs[i][1] + pre[s2[i][j] - 'a'])%mod;
		}
	}
	string t1, t2;
	long long ans = 0;
	for(int i = 1;i <= q;i++) {
		ans = 0;
		cin >> t1 >> t2;
		int sz = t1.size();
		for(int j = 0;j < sz;j++) {
			ht[0] = (ht[0] + pre[t1[j] - 'a'])%mod;
		}
		sz = t2.size();
		for(int j = 0;j < sz;j++) {
			ht[1] = (ht[1] + pre[t2[j] - 'a'])%mod;
		}
		for(int i = 1;i <= n;i++) {
			if((ht[0] - hs[i][0] + hs[i][1])%mod == ht[1]) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
