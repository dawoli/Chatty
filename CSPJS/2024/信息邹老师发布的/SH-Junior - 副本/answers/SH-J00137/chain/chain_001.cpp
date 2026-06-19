#include <bits/stdc++.h>
using namespace std;
#define int long long
int T,n,k,q,sum;
// vector<string> s[100010];

int lft[200010],rgt[200010];
int visLft[10],visRgt[10];

class DSU {
public :
    int fa[200010];
    void init(int m) {
        for (int i=1; i<=m; ++i) {
            fa[i] = i;
        }
    }
    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void unite(int x,int y) {
        fa[find(x)] = find(y);
    }
} dsu;

bool dp[100010][10];
// dp[i][j][k]表示对于前i个序列（人），末位为k nums

// string spl(string a,string b) {  // 字符串减法
//     string res = "";
//     if (a.size() < b.size()) {
//         swap(a,b);
//     }
//     for (int i=b.size(); i<=a.size()-1; ++i) {
//         res += a[i];  // 需确保a[i] == b[i]
//     }
//     return res;
// }

signed main() {
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld %lld",&n,&k,&q);
        sum = 0;
        for (int i=1; i<=n; ++i) {
            int l; scanf("%lld",&l), sum += l;
            int idx = 0;
            // s[i].push_back("");
            for (int j=1; j<=l; ++j) {
                string ele, afterele;
                cin >> ele;
                lft[++idx] = ele[0] - '0';
                rgt[idx] = ele[ele.size()-1] - '0';
                visLft[lft[idx]] = visRgt[rgt[idx]] = 1;
                if (j != 1) {
                    dsu.unite(idx,idx-1);
                }
            }
        }
        while (q--) {
            int r,c;
            scanf("%lld %lld",&r,&c);
            if (visLft[1] == 0 or visRgt[c] == 0) {
                printf("0\n");
                continue;
            }
//            dp[0][0][1] = 1;
//            for (int i=1; i<=n; ++i) {
//                for (int ); 
//            }
            printf("1\n");
        }
    }
    return 0;
}
