#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*

*/

const int N = 100001, N2=50005;
int t, n, n2, SP_A;
ll a[N][3], ans;

void dfs(int d, int s1, int s2, int s3, ll w) {
	if (d>n) {
		ans = max(ans, w);
		return;
	}
	if (s1<n2) dfs(d+1, s1+1, s2, s3, w+a[1][d]);
	if (s2<n2) dfs(d+1, s1, s2+1, s3, w+a[2][d]);
	if (s3<n2) dfs(d+1, s1, s2, s3+1, w+a[3][d]);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
    	SP_A = 1;
    	
        cin >> n;
        n2 = n/2;
        ans = 0ll;
        for (int i=1; i<=n; i++) {
			for (int c=1; c<=3; c++) {
				cin >> a[c][i];
				if (SP_A && c>1 && a[c][i]) SP_A = 0;
			}
        }
        if (SP_A) {
        	sort(a[1]+1, a[1]+n+1);
        	for (int i=n2+1; i<=n; i++) {
        		ans += a[1][i];
			}
		} else dfs(1, 0, 0, 0, 0ll);
        cout << ans << '\n';
    }
        
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
