#include <bits/stdc++.h>
using namespace std;
int cnt[100005];
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	memset(cnt, 0, sizeof(cnt));
	int n;
	cin >> n;
	while(n--){
		int r;
		cin >> r;
		cnt[r]++;
	}
	sort(cnt, cnt + 100005);
	cout << cnt[100004] << endl;
	return 0;
}
