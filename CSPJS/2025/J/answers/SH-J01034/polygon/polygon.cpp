#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5005;
const long long MOD = 998244353;
long long ans;
int n;
int a[N], s[N], vis[N];
int dp[N];
int C(int a, int b) {
    if(a > b) return 0;
    if(a == 0 || a == b) return 1;
    int res = 1, c = b - a;
    if(c > a) {
        for(int i = c+1;i <= b;i++) {
            res *= i;
        }
        for(int i = 1;i <= a;i++) {
            res /= i;
        }
    }
    else {
        for(int i = a+1;i <= b;i++) {
            res *= i;
        }
        for(int i = 1;i <= c;i++) {
            res /= i;
        }
    }
    return res;
}
void dfs(int Maxi, int curr, int Sum, int Count) {
    if(Count >= 3 && Sum > 2 * a[Maxi]) {
        for(int i = 0;i <= n-curr;i++) {
            ans = (ans + C(i, n-curr)) % MOD;
        }
        return;
    }
    for(int i = curr+1;i <= n;i++) {
        dfs(Maxi, i, Sum + a[i], Count+1);
    }
}
int main() {
    freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1, greater<int>());
    for(int i = 1;i <= n;i++) {
        dfs(i, i, a[i], 1);
    }
    cout << ans << '\n';
    return 0;
}
