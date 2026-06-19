#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e6 + 10;
char s[maxn];
ll len, a[maxn], cnt = 0;

bool cmp(ll cmp1, ll cmp2){return cmp1 > cmp2;}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	len = strlen(s);
	for (ll i = 0; i < len; i++){
		if (s[i] >= '0' && s[i] <= '9') a[++cnt] = s[i] - '0';
	}
	sort(a + 1, a + 1 + cnt, cmp);
	for (ll i = 1; i <= cnt; i++) cout << a[i];
	return 0;
}
