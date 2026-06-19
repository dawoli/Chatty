#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 205;
const int M = 1e5+5;

int T, n, a[M][3];
int f[N][N][N], tmp[M];
bool opA = true, opB = true, opC = true;

bool cmp(int i, int j){
	return i > j;
}

//struct node{
//	int val, idx;
//	bool operator < (const node & x) const {
//		return val > x.val;
//	}
//} tmp1[M];


inline void input(int& t){
	t = 0;
	char c = ' ';
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9'){
		t = t * 10 + (c - '0');
		c = getchar();
	}
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	input(T); 
	while(T--){
		input(n); 
		for(int i=1; i<=n; i++){
			input(a[i][1]); input(a[i][2]); input(a[i][3]); 
			if(a[i][3] != 0) opB = false, opA = false;
			if(a[i][2] != 0) opA = false;
		}
		if(n <= 200){
			for(int _=1; _<=n; _++){
				for(int i=0; i<=_; i++){
					for(int j=0; j<=_-i; j++){
						int k = _ -i -j;
						if(i > n/2 || j > n/2 || k > n/2) continue;
						f[_][i][j] =0;
						if(i > 0) f[_][i][j] = max(f[_][i][j], f[_-1][i-1][j] + a[_][1]);
						if(j > 0) f[_][i][j] = max(f[_][i][j], f[_-1][i][j-1] + a[_][2]);
						if(k > 0) f[_][i][j] = max(f[_][i][j], f[_-1][i][j] + a[_][3]);
	//					printf("%d %d %d: %d\n", i, j, k, f[_][i][j]);
					}
				}
			}
			int ans = 0;
			for(int i=0; i<=n; i++){
				for(int j=0; j<=n-i; j++){
					int k = n -i -j;
					ans = max(ans, f[n][i][j]);
				}
			}
			cout<<ans<<endl;
		} else if(opA == true){
			for(int i=1; i<=n; i++){
				tmp[i] = a[i][1];
			} sort(tmp+1, tmp+n+1, cmp);
			int ans = 0;
			for(int i=1; i<=n/2; i++){
				ans += tmp[i];
			}
			cout<<ans<<endl;
		} else if(opB == true){
			int ans = 0;
			for(int i=1; i<=n; i++){
				ans += a[i][1];
				tmp[i] = a[i][2] - a[i][1];
			} sort(tmp+1, tmp+n+1, cmp);
			for(int i=1; i<=n/2; i++){
				ans += tmp[i];
			}
			cout<<ans<<endl;
		} else {
			int ans = 0;
			for(int i=1; i<=n; i++){
				ans += max(a[i][1], max(a[i][2], a[i][3]));
			}
			cout<<ans<<endl;
//			for(int i=1; i<=n; i++){
//				tmp1[i] = {a[i][2] - a[i][1], i};
//			} sort(tmp1+1, tmp1+n+1);
//			for(int i=1; i<=n/2; i++){
//				int val = tmp1[i].val, idx = tmp1[i].idx;
//				a[idx][1] += val;
//			}
////			for(int i=1; i<=n; i++) cout<<a[i][1]<<" \n"[i==n];
//			int ans = 0;
//			for(int i=1; i<=n; i++){
//				ans += a[i][1];
//				tmp[i] = a[i][3] - a[i][1];
//			} sort(tmp+1, tmp+n+1, cmp);
//			for(int i=1; i<=n/2; i++){
//				if(tmp[i] < 0) break;
//				ans += tmp[i];
//			}
//			cout<<ans<<endl;
		}
	}
	return 0;
}

