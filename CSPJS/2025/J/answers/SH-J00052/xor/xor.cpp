#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N];
int pre[N], cnt = 0, cntc = 0;
int sum = 0;
int j, t, fin;
ll ans = 0;
struct node{
	int l, r;
}b[N], c[N];
bool cmp(node x, node y) {
	if(x.l == y.l) return x.r < y.r;
	return x.l < y.l;
}
void dfs(int pos, int f, ll cnt) {
	if(pos == cntc+1) {
		ans = max(ans, cnt);
		return ;
	}
	if(c[pos].l > f) {
		dfs(pos+1, c[pos].r, cnt+1);
	}
	dfs(pos+1, f, cnt);
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(register int i = 1; i <= n; ++i) {
		cin >> a[i];
		pre[i] = a[i] xor pre[i-1];
	}
	if(n <= 10) {
		for(register int l = 1; l <= n; ++l) {
			for(register int i = 1; i+l-1 <= n; ++i) {
				j = i+l-1;
				t = pre[j] xor pre[i-1];
				if(t == k) {
					++cnt;
					b[cnt].l = i, b[cnt].r = j; 
				}
			}
		}
		sort(b+1, b+1+cnt, cmp);
		for(register int i = 1; i <= cnt; ++i) {
			if(b[i].l != fin) {
				c[++cntc] = b[i];
				fin = c[cntc].l;
			}
		}
		dfs(1, 0, 0);
		cout << ans << endl;
	}
	else{
		for(register int i = 1; i <= n; ++i) {
			sum = sum xor a[i];
			if(sum == k || a[i] == k) {
				sum = 0;
				++ans;
			}
		}
		cout << ans << endl; 
	}
	return 0;
}
