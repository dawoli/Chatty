#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

int n;

int64 srch(vector< vector<int> > &a, int dpth, int64 ans, int d0, int d1, int d2){
	if (dpth == n) return ans;
	int64 ans0 = 0, ans1 = 0, ans2 = 0;
	if(d0 < n / 2) ans0 = srch(a, dpth + 1, ans + a[dpth][0], d0 + 1, d1, d2);
	if(d1 < n / 2) ans1 = srch(a, dpth + 1, ans + a[dpth][1], d0, d1 + 1, d2);
	if(d2 < n / 2) ans2 = srch(a, dpth + 1, ans + a[dpth][2], d0, d1, d2 + 1);
	return max(max(ans0, ans1), ans2);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		vector< vector<int> > a(n + 1, vector<int>(3));
		for(int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2];
		cout << srch(a, 0, 0, 0, 0, 0) << endl;
	}
	
	return 0;
}
