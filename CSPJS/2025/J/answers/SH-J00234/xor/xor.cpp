#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s[500005],ans,cnt,lst;
struct Node{int l,r;}b[1000005];
bool cmp(Node x,Node y){
	if (x.r == y.r) return (x.r - x.l + 1) < (y.r - y.l + 1);
	return x.r < y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i],s[i] = s[i - 1] ^ a[i];
	for (int len = 1;len <= n;len++){
		for (int i = 1;i + len - 1 <= n;i++){
			int j = i + len - 1;
			if ((s[j] ^ s[i - 1]) == k) b[++cnt].l = i,b[cnt].r = j;
		}
	}
	sort(b + 1,b + cnt + 1,cmp);
	for (int i = 1;i <= cnt;i++) if (b[i].l > lst) ans++,lst = b[i].r;
	cout << ans;
	return 0;
}
