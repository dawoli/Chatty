#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

long long n, a[N], cnt[N], maxn, idx = 1, tmp, cur, ans;

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		maxn = max(maxn, a[i]);
		cnt[a[i]]++;
	}
	for(int i=2; i<=maxn; i++){
		cur = cnt[i];
		while(idx != i && cur > 0){
			tmp = min(cnt[idx], cnt[i]);
			cnt[idx] -= tmp;
			cur -= tmp;
			if(cnt[idx] == 0) idx++;
		}
	}	
	for(int i=2; i<=maxn; i++){
		ans += cnt[i];
	}
	cout<<ans;
//	cout<<cnt[1]<<" "<<cnt[2];
//	cout<<n - cnt[2];
	return 0;
}
