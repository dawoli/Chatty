#include <bits/stdc++.h>
using namespace std;
int t,n,ans,s[100001];
struct node {
	int a,b,c,maxm,sum;
} st[100001];
bool cmp(const node& s1,const node& s2) {
	return s1.a>s2.a;
}
bool cmp1(const node& s1,const node& s2) {
	return s1.b>s2.b;
}
bool cmp2(const node& s1,const node& s2) {
	return s1.sum>s2.sum;
}
void dfs(int i,int a,int b,int c,int sum) {
	if(i == n+1) {
		ans = max(ans,sum);
		return;
	}
	if(sum + s[n] - s[i-1] <= ans) return;
	if(a < (n>>1)) dfs(i+1,a+1,b,c,sum+st[i].a);
	if(b < (n>>1)) dfs(i+1,a,b+1,c,sum+st[i].b);
	if(c < (n>>1)) dfs(i+1,a,b,c+1,sum+st[i].c);
}
void solve() {
	bool f=0,f2=0;
	ans =0;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> st[i].a >> st[i].b >> st[i].c;
		f |= st[i].b;
		f2 |= st[i].c;
		st[i].maxm = max(st[i].a,max(st[i].b,st[i].c));
		s[i] = s[i-1] + st[i].maxm;
		st[i].sum = st[i].a+st[i].b+st[i].c;
	}
	if(n <= 30) {
		dfs(1,0,0,0,0);
		cout << ans << endl;
	} else if(!f) {
		sort(st+1,st+n+1,cmp);
		for(int i=1; i<=n>>1; ++i) ans += st[i].a;
		cout << ans << endl;
	} else if(!f2) {
		sort(st+1,st+n+1,cmp2);
		int a=0,b=0;
		for(int i=1; i<=n; ++i) {
			if(st[i].a>st[i].b) if(a < n>>1)++a,ans += st[i].a;
				else ++b,ans += st[i].b;
			if(st[i].a<=st[i].b) if(b < n>>1)++b,ans += st[i].b;
				else ++a,ans += st[i].a;

		}
		cout << ans << endl;
	} else {
		for(int i=1; i<=n; ++i) {
			int k = max(st[i].a,max(st[i].b,st[i].c));
			ans += k;
		}
		cout << ans << endl;
	}
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--) solve();
}
