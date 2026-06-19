#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N][5], vis[N], c[N], n, ans = 0;

struct node{
	int val;
	int idx;
}b1[N], b2[N], b3[N];

bool cmp(node x, node y){
	return x.val > y.val;
}

void solve(){
	ans = 0;
	cin >> n;
	c[1] = 1; c[2] = 1; c[3] = 1;
	for(int i = 1; i <= n; i ++){
		vis[i] = 0;
		b1[i].val = b1[i].idx = 0;
		b2[i].val = b2[i].idx = 0;
		b3[i].val = b3[i].idx = 0;
	}
	for(int i = 1; i <= n; i ++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		int maxi = max({a[i][1], a[i][2], a[i][3]});
		int mini = min({a[i][1], a[i][2], a[i][3]});
		int mid = a[i][1] + a[i][2] + a[i][3] - maxi - mini;
		if(maxi == a[i][1]){
			b1[i].val = maxi - mid;
			b1[i].idx = i;
		}else if(maxi == a[i][2]){
			b2[i].val = maxi - mid;
			b2[i].idx = i;
		}else{
			b3[i].val = maxi - mid;
			b3[i].idx = i;
		}	
	}
	sort(b1 + 1, b1 + n + 1, cmp);
	sort(b2 + 1, b2 + n + 1, cmp);
	sort(b3 + 1, b3 + n + 1, cmp);
	for(int i = 1; i <= n / 2; i ++){
		int j = b1[i].idx;
		if(b1[i].val != 0 && !vis[j]){
			ans += a[j][1];
			vis[j] = 1;
		}
	}
	for(int i = 1; i <= n / 2; i ++){
		int j = b2[i].idx;
		if(b2[i].val != 0 && !vis[j]){
			ans += a[j][2];
			vis[j] = 1;
		}
	}
	for(int i = 1; i <= n / 2; i ++){
		int j = b3[i].idx;
		if(b3[i].val != 0 && !vis[j]){
			ans += a[j][3];
			vis[j] = 1;
		}
	}
	if(b1[n / 2 + 1].val != 0) c[1] = 0;
	if(b2[n / 2 + 1].val != 0) c[2] = 0;
	if(b3[n / 2 + 1].val != 0) c[3] = 0;
	for(int i = 1; i <= n; i ++){
		if(!vis[i]){
			int maxi = - 1;
			for(int j = 1; j <= 3; j ++){
				if(c[j]) maxi = max(maxi, a[i][j]);
			}
			ans += maxi;
		}
	}
	cout << ans << endl;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = 0;
	cin >> t;
	for(int i = 1; i <= t; i ++) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
