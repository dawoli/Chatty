#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 305;
const int MOD = 998244353;

int n;
vector<int> pre, post, in;
int dp[MAXN][MAXN];
bool vis[MAXN];

void input() {
    cin >> n;
    pre.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) cin >> post[i];
}

int count_trees(int l, int r, int pl, int pr) {
    if (l > r) return 1;
    if (l == r) return 1;
    if (dp[l][r] != -1) return dp[l][r];
    
    int root = pre[pl];
    int pos = find(post.begin() + l, post.begin() + r, root) - post.begin();
    int left_size = pos - l;
    
    long long res = 1LL * count_trees(l, pos - 1, pl + 1, pl + left_size) * 
                    count_trees(pos + 1, r - 1, pl + left_size + 1, pr - 1);
    return dp[l][r] = res % MOD;
}

void reconstruct(int l, int r, int pl, int pr) {
    if (l > r) return;
    int root = pre[pl];
    in.push_back(root);
    vis[root] = true;
    
    if (l == r) return;
    
    int pos = find(post.begin() + l, post.begin() + r, root) - post.begin();
    int left_size = pos - l;
    
    for (int i = pl + 1; i <= pr; i++) {
        if (!vis[pre[i]]) {
            reconstruct(l, pos - 1, pl + 1, pl + left_size);
            break;
        }
    }
    
    for (int i = pl + 1; i <= pr; i++) {
        if (!vis[pre[i]]) {
            reconstruct(pos + 1, r - 1, i, pr - 1);
            break;
        }
    }
}

void output() {
    cout << count_trees(0, n - 1, 0, n - 1) << endl;
    reconstruct(0, n - 1, 0, n - 1);
    for (int i = 0; i < in.size(); i++) {
        cout << in[i];
        if (i < in.size() - 1) cout << " ";
    }
    cout << endl;
}

int main() {
//	freopen("tree.in", "r", stdin);
//	freopen("tree.out", "w", stdout);
    memset(dp, -1, sizeof(dp));
    input();
    output();
    return 0;
}
