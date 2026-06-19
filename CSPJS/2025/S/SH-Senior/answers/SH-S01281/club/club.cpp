#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int T, n, a[N][5], dp[205][205][205], tmp[N];
//vector<int> v1, v2, v3;
//bool cmp1(const int &x, const int &y){
//	return a[x][1] < a[y][1];
//}
//bool cmp2(const int &x, const int &y){
//	return a[x][2] < a[y][2];
//}
//bool cmp3(const int &x, const int &y){
//	return a[x][3] < a[y][3];
//}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	
	cin >> T;
	while(T --){
		int ans = 0;
		memset(dp, 0, sizeof(dp));
//		v1.clear(), v2.clear(), v3.clear();
		cin >> n;
		for(int i = 1; i <= n; ++ i){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
//			if(a[i][1] > a[i][2] && a[i][1] > a[i][3])
//				v1.push_back(i), ans += a[i][1];
//			else if(a[i][2] > a[i][1] && a[i][2] > a[i][3])
//				v2.push_back(i), ans += a[i][2];
//			else
//				v3.push_back(i), ans += a[i][3];
		}
		
		bool flag = true;
		for(int i = 1; i <= n; ++ i)
			if(a[i][2] || a[i][3]){
				flag = false;
				break;
			}
		
		if(flag){
			for(int i = 1; i <= n; ++ i)
				tmp[i] = a[i][1];
			
			sort(tmp + 1, tmp + n + 1);
			
			for(int i = n; i > n / 2; -- i)
				ans += tmp[i];
			cout << ans << endl;
			continue;
		}
		
		for(int i = 1; i <= n; ++ i){
			for(int x = 0; x <= min(i, n / 2); ++ x){
//				printf("min(i - x, n / 2) = %d\n", min(i - x, n / 2));
//				for(int y = 0; y <= min(i - x, n / 2); ++ y){
//					cout << 0 << endl;
//				}
				for(int y = min(i - x, n / 2); y >= 0; -- y){
					int z = i - x - y;
//					printf("i = %d, x = %d, y = %d, z = %d, i - x = %d\n", i, x, y, z, i - x);
					if(z > n / 2)
						break;
					
					if(x)
						dp[i][x][y] = dp[i - 1][x - 1][y] + a[i][1];
//					printf("i = %d, x = %d, y = %d, z = %d, dp = %d\n", i, x, y, z, dp[i][x][y]);
					if(y)
						dp[i][x][y] = max(dp[i][x][y], dp[i - 1][x][y - 1] + a[i][2]);
//					printf("dp2 = %d\n", dp[i][x][y]);
					if(z)
						dp[i][x][y] = max(dp[i][x][y], dp[i - 1][x][y] + a[i][3]);
//					printf("i = %d, x = %d, y = %d, z = %d, dp = %d\n", i, x, y, z, dp[i][x][y]);
//					printf("dp3 = %d\n", dp[i][x][y]);
				}
			}
		}
		
		for(int x = 0; x <= n / 2; ++ x)
			for(int y = 0; y <= min(n - x, n / 2); ++ y)
				ans = max(ans, dp[n][x][y]);
		cout << ans << endl;
//		sort(v1.begin(), v1.end(), cmp1);
//		sort(v2.begin(), v2.end(), cmp2);
//		sort(v3.begin(), v3.end(), cmp3);
//		
//		int t1 = ans, t2 = ans, t3 = ans;
//		if(v1.size() > n / 2){
//			for(int i = 0; i < v1.size() - n / 2; ++ i){
//				t1 -= a[v1[i]][1];
//				t1 += max(a[v1[i]][2], a[v1[i]][3]);
//			}
//		}
//		if(v2.size() > n / 2){
//			for(int i = 0; i < v2.size() - n / 2; ++ i){
//				t2 -= a[v2[i]][2];
//				t2 += max(a[v2[i]][1], a[v2[i]][3]);
//			}
//		}
//		if(v3.size() > n / 2){
//			for(int i = 0; i < v3.size() - n / 2; ++ i){
//				t3 -= a[v3[i]][3];
//				t3 += max(a[v3[i]][1], a[v3[i]][2]);
//			}
//		}
//		cout << min(t1, min(t2, t3)) << endl;
	}
	return 0;
}
