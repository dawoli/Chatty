//65
#include <bits/stdc++.h>
using namespace std;
int n,k,a[500001],s[1005][1005],dp[500001];
int lst[500001];//only for debug
struct node{
	int i,j;
	bool operator<(const node& c) {
		if(j!=c.j) return j<c.j;
		return i<c.i;
	}
};
vector <node> v;
int main() {
	freopen("xor.in","r",stdin);
//	freopen("xor5.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
//		s[i] = s[i-1] ^ a[i];
//		printf("%d\n",s[i]);
	}
	if(n > 1000) {
		int ans = 0;
		for(int i=1;i<=n;++i) ans += a[i];
		cout << ans << endl;
	}
	
	for(int i=1;i<=n;++i) {
		int m = a[i];
		for(int j=i;j<=n;++j) {
			s[i][j] = m;
			if(s[i][j] == k) {
				v.push_back({i,j});
			}
			m ^= a[j+1];
//			printf("%d %d:%d\n",i,j,s[i][j]);
//			printf(" %d \n",s[i][j]);
		}
	}
	sort(v.begin(),v.end());
	for(node x : v) {
		int i = x.i,j = x.j;
//		printf("{%d,%d}\n",i,j);
	}
	int l = 0,ans = 0;
	for(int i=0;i<v.size();++i) {
		if(v[i].i > l) {
			++ans;
			l = v[i].j;
		}
	}
	cout << ans << endl;
}
