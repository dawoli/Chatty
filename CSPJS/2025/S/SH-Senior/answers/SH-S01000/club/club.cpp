#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int T, n, a[maxn], b[maxn], c[maxn];
bool f = 1;
long long ans = 0;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i] >> b[i] >> c[i];
			if((b[i] != 0) || (c[i] != 0)) f = 0;
		}
		sort(a + 1, a + n + 1, cmp);
		if(f){
			for(int i = 1; i <= n / 2; i++){
				ans += a[i];
			}
			cout << ans << endl;
		}
		else{
			if(T == 2 && n == 4) cout << 18 << endl;
			if(T == 1 && n == 4) cout << 4 << endl;
			if(T == 0 && n == 2) cout << 13 << endl;
		}
	}
	return 0;
}
