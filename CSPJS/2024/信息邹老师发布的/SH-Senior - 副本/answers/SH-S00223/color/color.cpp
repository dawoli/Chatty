#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;

int T;
int n, a[200005];
bool mem[105][105][105];
int dp[105][105][105]; 

int solve(int step, int red, int blue){
	if (step == n) return 0;
	if (mem[step][red][blue]) return dp[step][red][blue];
	int way1 = solve(step + 1, a[step], blue) + a[step] * (a[step] == red);
	int way2 = solve(step + 1, red,  a[step]) + a[step] * (a[step] ==blue);
	mem[step][red][blue] = true;
	return dp[step][red][blue] = max(way1, way2);
}

void testcase(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cout << solve(0, 0, 0); 
}

signed main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	cin >> T;
	while (T --){
		memset(mem, false, sizeof(mem));
		memset(dp, 0, sizeof(dp));
		testcase();
		cout << endl;
	}
	return 0;
}
