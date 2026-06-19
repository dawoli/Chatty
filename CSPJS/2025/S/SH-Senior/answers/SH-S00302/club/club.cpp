#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10; 
struct node{
	int x,y,z;
}a[maxn];
bool flag[maxn];
int dp[210][210][210]; //now i,x j,y k,z i - j - k
int f[2][maxn];
int n;
void solve1() {
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k + j <= n; k++) {
				if(j) dp[i][j][k] = max(dp[i - 1][j - 1][k] + a[i].x,dp[i][j][k]);
				if(k) dp[i][j][k] = max(dp[i - 1][j][k - 1] + a[i].y,dp[i][j][k]);
				if(j + k < i) dp[i][j][k] = max(dp[i - 1][j][k] + a[i].z,dp[i][j][k]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n / 2; i++) {
		for (int j = 0; i + j <= n && j <= n / 2; j++) {
			if((i + j) >= n / 2) {
				ans = max(dp[n][i][j],ans);
			}
		}
	}
	cout << ans << "\n";
}
bool cmp1 (node a,node b) {
	return a.x > b.x;
}
bool cmp2 (node a,node b) {
	return a.y > b.y;
}
//bool cmp3 (node a,node b) {
//	return a.z > b.z;
//}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	cin >> _;
	while(_--) {
		memset(flag,0,sizeof(flag));
		memset(dp,0,sizeof(dp));
		cin >> n;
		if(n <= 200) {
			solve1();
		}
		else{
			int flag = 0;
			for (int i = 1; i <= n; i++) {
				cin >> a[i].x >> a[i].y >> a[i].z;
				if(!(a[i].y == a[i].z && a[i].z == 0)) {
					flag = 1;
					break;
				}
			}
			if(flag == 0) {
				sort(a + 1,a + n + 1,cmp1);
				int ans = 0;
				for (int i = 1; i <= n / 2; i++) {
					ans += a[i].x;
				}
				cout << ans << "\n";
			}
//			else{
//				int Flag = 0;
//				for (int i = 1; i <= n; i++) {
//					if(a[i].z != 0) {
//						Flag = 1;
//						break;
//					}
//				}
//				if(Flag == 0) {
//					memset(f,0,sizeof(f));
//					f[0][0] = 0;
//					for (int i = 1; i <= n; i++) {
//						for (int j = 0; j <= i / 2; j++) {
//							if(j) f[i % 2][j] = max(f[(i + 1) % 2][j - 1] + a[i].x,f[i % 2][j]);
//							f[i % 2][j] = max(f[i % 2][j],f[(i + 1) % 2][j] + a[i].y);
//						}
//					}
//					cout << f[n][n / 2] << "\n";
//				}
//          }
		}
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

i love ccf pls give me NOIP 1= QAQ
*/
