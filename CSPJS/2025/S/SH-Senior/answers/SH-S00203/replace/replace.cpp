# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <ull, ull> P;

const ll bas = 13331;
const ll mod = 998244353;
const int N = 200010;
ll n, q;
ull pw[N];
vector <ull> hass[N][3], hast[3];
string s[N][3];
map <P, ll> cnt;

P ask(ll l, ll r)
{
	return {(hast[1][r] - hast[1][l - 1] * pw[r - l + 1] % mod + mod) % mod, (hast[2][r] - hast[2][l - 1] * pw[r - l + 1] % mod + mod) % mod};
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%lld%lld", &n, &q);
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][1] >> s[i][2];
//		pw[i] = pw[i - 1] * bas % mod;
		hass[i][1].resize(s[i][1].size() + 1);
		hass[i][2].resize(s[i][2].size() + 1);
		for (int j = 1; j <= s[i][1].size(); j++)
		{
			hass[i][1][j] = (hass[i][1][j - 1] * bas % mod + (s[i][1][j - 1] - 'a')) % mod;
			hass[i][2][j] = (hass[i][2][j - 1] * bas % mod + (s[i][2][j - 1] - 'a')) % mod;
//			cout<<hass[i][1][j]<<" "<<hass[i][2][j]<<endl;
		}
		cnt[{hass[i][1][s[i][1].size()], hass[i][2][s[i][2].size()]}]++;
//		cout<<hass[i][1][s[i][1].size()] <<" "<< hass[i][2][s[i][2].size()]<<endl;
	}
	while (q--)
	{
		string t1, t2;//diff, to;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) printf("0\n");
		else
		{
			ll len, d1, d2;//, hasd, hast;
			len = t1.size();
			hast[1].resize(len + 1), hast[2].resize(len + 1);
//			diff = to = "";
			bool flg;
			flg = true;
			d1 = 1e9, d2 = -1e9;
			for (ll i = 1; i <= len; i++)
			{
				pw[i] = pw[i - 1] * bas % mod;
				hast[1][i] = (hast[1][i - 1] * bas % mod + (t1[i - 1] - 'a')) % mod;
				hast[2][i] = (hast[2][i - 1] * bas % mod + (t2[i - 1] - 'a')) % mod;
				if (t1[i - 1] != t2[i - 1]) d1 = min(d1, i), d2 = max(d2, i);
//				else if (i >= 3 && t1[i - 3] != t2[i - 3] && t1[i - 2] == t2[i - 2]) flg = false;
			}
//			cout<<d1<<" "<<d2<<endl;
//			if (!flg)
//			{
//				printf("0\n");
//				continue;
//			}
			ll ans;
			ans = 0;
			for (int i = 1; i <= d1; i++)
			{
				for (int j = d2; j <= len; j++)
				{
					P a;
					a = ask(i, j);
//					cout<<a.first<<" "<<a.second<<endl;
					ans += cnt[a];
				}
			}
//			cout<<diff<<" "<<to<<" "<<flg<<endl;
//			cout<<"Check Right"<<endl;
//			len = diff.size();
//			hasd = hast = 0;
//			for (int i = 1; i <= len; i++)
//			{
//				hasd = hasd * bas + diff[i - 1] - 'a';
//				hast = hast * bas + to[i - 1] - 'a';
//			}
//			cout<<hasd<<" "<<hast<<endl;
//			ll ans;
//			ans = 0;
//			for (int i = 1; i <= n; i++)
//			{
//				if (hass[i][1][s[i][1].size()] == hasd && hass[i][2][s[i][2].size()] == hast) ans++;
//			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
