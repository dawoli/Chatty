#include <bits/stdc++.h>
using namespace std;
#define int long long

int T,n,a[200010],c[200010];

class FenwickTree {
    int bit[200010];
    int lowbit(int x) {
        return x & -x;
    }
public :
    void update(int p,int d) {
        while (p <= n) {
            bit[p] += d;
            p += lowbit(p);
        }
    }
    int queryR(int p) {
        int res = 0;
        while (p) {
            res += bit[p];
            p -= lowbit(p);
        }
        return res;
    }
    int query(int l,int r) {
        return queryR(r) - queryR(l-1);
    }
} Fenwick;

// int dp[20][67000];
// 状压写法（拿1~4的20分）：
// dp[i][j]表示对于前i个数，状态为j时的最大价值

// int dp[200010][2];
// dp[i][0]表示对于前i个数，i不选（染红色）时的最大得分
// dp[i][1]表示对于前i个数，i选了（染蓝色）时的最大得分

// int dp[2010][2010];
// 区间写法（拿1~10的50分）：
// dp[i][j]表示从i到j的最大价值

signed main() {
    // freopen("color.in","r",stdin);
    // freopen("color.out","w",stdout);
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&n);
        for (int i=1; i<=n; ++i) {
            scanf("%lld",&a[i]);
        }
        memset(c,0,sizeof(c));  // 多测不清空，OI见祖宗
    }
    return 0;
}