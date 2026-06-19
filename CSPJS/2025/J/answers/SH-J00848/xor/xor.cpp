#include <iostream>
using namespace std;
const int MAXN = 5e5+5;
int a[MAXN]={0}, n, k, pre[MAXN]={0}, ans=0;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
		if(a[i]) pre[i]=pre[i-1]+1;
		else pre[i]=pre[i-1];
	}
	if(k==0) {
		for(int i = 1;i <= n;i ++) {
			if(a[i] == 0) {ans++; continue;}
			int cur=0;
			while(a[i]==0 && i <= n) i++,cur++;
			if(i==n+1) i--;
			ans+=cur/2;
		}
	} else {
		ans = pre[n];
	}
	cout << ans << '\n';
	return 0;
}
