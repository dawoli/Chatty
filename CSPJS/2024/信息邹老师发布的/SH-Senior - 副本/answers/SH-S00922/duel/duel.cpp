#include <bits/stdc++.h>
int cnt[100005];
bool flag[100005];
using namespace std;
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	int k = 0;
	int a[100005];
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		cnt[x]++;
		if(!flag[x]){
			flag[x] = 1;
			k++;
			a[k] = x;
		}
	}
	sort(a + 1, a + k + 1);
	int die = 0;
	for(int i = 1 ; i < k ; i++){
		die += min(cnt[a[i]], cnt[a[i + 1]]);
	}
	cout << n - die;
}
