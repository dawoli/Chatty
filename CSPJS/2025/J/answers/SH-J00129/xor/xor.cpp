#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int a[500005], s[500005], cur;
vector<int> v[500005];
map<int, int> mp;
struct node{
	int l, r;
} b[500005];
int cnt;
bool cmp(node x, node y){
	return x.r < y.r;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++){
		s[i] = s[i-1] ^ a[i];
		if (!mp.count(s[i])) mp[s[i]] = ++cur;
		v[mp[s[i]]].push_back(i);
	}
	for (int i = 0; i <= n; i++){
		if (!mp.count(k ^ s[i])) continue;
		int tg = mp[k ^ s[i]];
		int t = upper_bound(v[tg].begin(), v[tg].end(), i) - v[tg].begin();
		if (t >= v[tg].size()) continue;
		b[++cnt] = {i, v[tg][t]};
	}
	sort(b+1, b+cnt+1, cmp);
	int now = 0, ans = 0;
	for (int i = 1; i <= cnt; i++){
		if (b[i].l < now) continue;
		ans++, now = b[i].r;
	}
	cout << ans << '\n';
	return 0;
}
