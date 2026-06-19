#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n;
struct Node{
	int x, y, z;
}a[N];
bool cmp1(Node m, Node k){
	if(m.x == k.x){
		if(m.y == k.y) return m.z > k.z;
		else return m.y > k.y;
	}
	return m.x > k.x;
}
bool cmp2(Node m, Node k){
	if(m.x == k.x){
		if(m.z == k.z) return m.y > k.y;
		else return m.z > k.z;
	}
	return m.x > k.x;
}
bool cmp3(Node m, Node k){
	if(m.y == k.y){
		if(m.z == k.z) return m.x > k.x;
		else return m.z > k.z;
	}
	return m.y > k.y;
}
bool cmp4(Node m, Node k){
	if(m.y == k.y){
		if(m.x == k.x) return m.z > k.z;
		else return m.x > k.x;
	}
	return m.y > k.y;
}
bool cmp5(Node m, Node k){
	if(m.z == k.z){
		if(m.x == k.x) return m.y > k.y;
		else return m.x > k.x;
	}
	return m.z > k.z;
}
bool cmp6(Node m, Node k){
	if(m.z == k.z){
		if(m.y == k.y) return m.x > k.x;
		else return m.y > k.y;
	}
	return m.z > k.z;
}
int maxn[10];
long long maxm = 0;
long long cnt;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			maxn[2] = max(maxn[2], a[i].y);
			maxn[3] = max(maxn[3], a[i].z);
		}
		sort(a + 1, a + n + 1, cmp1);
		if(maxn[2] == 0 && maxn[3] == 0){
			for(int i = 1; i <= n / 2; i++){
				cnt += a[i].x;
			}
			cout << cnt << endl;
			continue;
		}
		for(int k = 1; k <= 6; k++){
			if(k == 1){
//				cout << "--------" << endl;
				sort(a + 1, a + n + 1, cmp1);
				for(int i = 0; i <= n / 2; i++){
					for(int j = i; j <= n; j++){
						if(j - i > n / 2 || n - j > n / 2) continue;
						cnt = 0;
						for(int m = 1; m <= n; m++){
							if(m > 0 && m <= i) cnt += a[m].x;
							if(m > i && m <= j) cnt += a[m].y;
							if(m > j && m <= n) cnt += a[m].z;
						}
//						cout << cnt << endl;
						maxm = max(maxm, cnt);
					}
				}
			}
			if(k == 2){
//				cout << "--------" << endl;
				sort(a + 1, a + n + 1, cmp2);
				for(int i = 0; i <= n / 2; i++){
					for(int j = i; j <= n; j++){
						if(j - i > n / 2 || n - j > n / 2) continue;
						cnt = 0;
						for(int m = 1; m <= n; m++){
							if(m > 0 && m <= i) cnt += a[m].x;
							if(m > i && m <= j) cnt += a[m].z;
							if(m > j && m <= n) cnt += a[m].y;
						}
//						cout << cnt << endl;
						maxm = max(maxm, cnt);
					}
				}
			}
			if(k == 3) {
//				cout << "--------" << endl;
				sort(a + 1, a + n + 1, cmp3);
				for(int i = 0; i <= n / 2; i++){
					for(int j = i; j <= n; j++){
						if(j - i > n / 2 || n - j > n / 2) continue;
						cnt = 0;
						for(int m = 1; m <= n; m++){
							if(m > 0 && m <= i) cnt += a[m].y;
							if(m > i && m <= j) cnt += a[m].z;
							if(m > j && m <= n) cnt += a[m].x;
						}
//						cout << cnt << endl;
						maxm = max(maxm, cnt);
					}
				}
			}
			if(k == 4) {
//				cout << "--------" << endl;
				sort(a + 1, a + n + 1, cmp4);
				for(int i = 0; i <= n / 2; i++){
					for(int j = i; j <= n; j++){
						if(j - i > n / 2 || n - j > n / 2) continue;
						cnt = 0;
						for(int m = 1; m <= n; m++){
							if(m > 0 && m <= i) cnt += a[m].y;
							if(m > i && m <= j) cnt += a[m].x;
							if(m > j && m <= n) cnt += a[m].z;
						}
//						cout << cnt << endl;
						maxm = max(maxm, cnt);
					}
				}
			}
			if(k == 5) {
//				cout << "--------" << endl;
				sort(a + 1, a + n + 1, cmp5);
				for(int i = 0; i <= n / 2; i++){
					for(int j = i; j <= n; j++){
						if(j - i > n / 2 || n - j > n / 2) continue;
						cnt = 0;
						for(int m = 1; m <= n; m++){
							if(m > 0 && m <= i) cnt += a[m].z;
							if(m > i && m <= j) cnt += a[m].x;
							if(m > j && m <= n) cnt += a[m].y;
						}
//						cout << cnt << endl;
						maxm = max(maxm, cnt);
					}
				}
			}
			if(k == 6) {
//				cout << "--------" << endl;
				sort(a + 1, a + n + 1, cmp6);
				for(int i = 0; i <= n / 2; i++){
					for(int j = i; j <= n; j++){
						if(j - i > n / 2 || n - j > n / 2) continue;
						cnt = 0;
						for(int m = 1; m <= n; m++){
							if(m > 0 && m <= i) cnt += a[m].z;
							if(m > i && m <= j) cnt += a[m].y;
							if(m > j && m <= n) cnt += a[m].x;
						}
//						cout << cnt << endl;
						maxm = max(maxm, cnt);
					}
				}
			}
		}
		cout << maxm << endl;
		maxm = 0;
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
