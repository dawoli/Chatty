#include <bits/stdc++.h>
using namespace std;
/*
前面预处理是好做的，dp有点难想。
先考虑做一个前缀异或和，方便快速query
然后做每一个点，以这个点为l边界的合法区间长度，加到那个gnl数组里面
然后dp
*//*
luogu 782768 #define int long long
feropen froepen freopen
freopen("xor.out", "r", stdin);
freopen("xor.in", "w", stdin);
*/
const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f; 
int a[N], n, k;
int prexor[N];
int dp[N];
vector <int> gnl[N];
int query(int l, int r){ return prexor[r] ^ prexor[l - 1]; };
signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	prexor[0] = 1;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		prexor[i] = prexor[i - 1] ^ a[i];
	}
	
	//cout << query(1, 2) << endl << query(4, 4); 

	for (int i = 1; i <= n; i ++){
		for (int length = 0; length + i <= n; length ++){
			if (query(i, i + length) == k){
				gnl[i + length + 1].push_back(i);
				break;
			}
		}
	}
	for (int i = 1; i <= n; i ++){
		//cout << (lng[i] == INF ? -1 : lng[i]) << ' ';
	} //cout << endl;
	for (int i = 1; i <= n + 1; i ++){
		dp[i] = max(dp[i], dp[i - 1]);
		for (auto j : gnl[i]){
			dp[i] = max(dp[j] + 1, dp[i]);
		}
		//dp[i] = max(dp[i + lng[i]] + 1, dp[i]);
	}
	int ans = -1; 
	for (int i = 1; i <= n + 1; i ++){
		//cout << dp[i] << ' ';
		ans = max(ans, dp[i]);
	} //cout << endl;
	cout << ans;
	//cout << dp[1];
}
