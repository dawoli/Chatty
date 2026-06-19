#include<bits/stdc++.h>
const int N = 500 + 5,mod = 998244353;
int c[N],p[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	int n,m;std::cin >> n >> m;
	std::string s;std::cin >> s;
	for (int i = 1;i <= n;i++) std::cin >> c[i];
	for (int i = 1;i <= n;i++) p[i] = i;
	int ans = 0;
	do{
		int refu = 0;
		for (int i = 1;i <= n;i++)
			if (s[i - 1] == '0' || refu >= c[p[i]]) ++refu;
		if (n - refu >= m && ++ans >= mod) ans -= mod;
	}while (std::next_permutation(p + 1,p + 1 + n));
	std::cout << ans << '\n';
	return 0;
	return 0;
}
