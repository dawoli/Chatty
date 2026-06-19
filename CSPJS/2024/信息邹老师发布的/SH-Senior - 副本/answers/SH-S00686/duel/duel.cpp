#include<bits/stdc++.h>
using namespace std;

int n;
int a[110000];
int cnt[110000];
int minn = 110000;
int maxn = -1;
int ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	ans = n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		minn = min(minn , a[i]);
		maxn = max(maxn , a[i]);
		cnt[a[i]]++;
	}
	cnt[0] = cnt[minn];
	for(int i = minn + 1; i <= maxn; i++) {
		if(cnt[i] == 0) continue;
		else {
			if(cnt[i] >= cnt[0]) {
				ans -= cnt[0];
				cnt[0] = cnt[i];
			}
			else {
				ans -= cnt[i];
			}
		}
	}
	
	cout << ans;
	
	
	
	return 0;
}
