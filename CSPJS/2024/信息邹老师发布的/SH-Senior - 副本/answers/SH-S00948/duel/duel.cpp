#include<bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 1e5+7;

int r[MAXN];
int a[MAXN];

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &r[i]);
	}
	sort(r,r+n);
	for(int i = 0; i < r[n]; i++){
		a[r[i++]]++;
	}
	int cnt = a[r[0]];
	for(int i = r[0]; i < r[n]; i++){
		cnt = max(cnt, a[i]);
	}
	cout << cnt;
	return 0;
}
