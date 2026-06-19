#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a0[100010], c[100010], k0, T, x[10], a[100010], k, ans[100010];
string arena[20];
ll tree[500010], id[500010]; bool ishost[500010];
void dfs(int index, int anspos) {
    if(tree[index] != 1e18) {
        if(!ishost[index]) ans[anspos] += id[index];
        return;
    }
    //cerr << "Dfs to index " << index << ", verified. \n";
    if(index >= (1 << k)) {
        ans[anspos] += (index - (1 << k) + 1); 
        //cerr << "During dfs, ans[" << anspos << "]+=" << index - (1 << k) + 1 << endl;
        return; 
    }
    dfs(index << 1, anspos);
    dfs((index << 1) + 1, anspos);
}

int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%lld%lld", &n, &m); k0 = ceil(log2(n));
    for(int i = 1; i <= n; ++i) scanf("%lld", &a0[i]);
    for(int i = 1; i <= m; ++i) scanf("%lld", &c[i]);
    for(int i = 1; i <= k0; ++i) {
        cin >> arena[i];
        //cerr << "arena[i]=" << arena[i] << endl;
    }
    scanf("%lld", &T);
    //cerr << "T=" << T << endl;
for(int times = 1; times <= T; ++times) {
    for(int i = 0; i <= 3; ++i) scanf("%lld", &x[i]);
    for(int i = 1; i <= n; ++i) a[i] = a0[i] ^ x[i % 4];
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= m; ++i) {
        memset(tree, 0, sizeof(tree));
        memset(ishost, 0, sizeof(ishost));
        //cerr << "Task " << times << " - case " << i << "; c[i]=" << c[i] << endl;
        k = ceil(log2(c[i]));
        for(int j = 0; j < c[i]; ++j) {tree[j + (1 << k)] = a[j + 1]; id[j + (1 << k)] = j + 1; }
        for(int j = c[i] + (1 << k); j < (1 << (k + 1)); ++j) {tree[j] = 1e18; id[j] = j - (1 << k) + 1; }
        //for(int j = 1; j < (1 << (k + 1)); ++j) cerr << tree[j] << " ";
        //cerr << endl;
        for(int j = 1; j <= k; ++j) {       //=>arena[j+k0-k]
            for(int x = 0; x < (1 << (k - j)); ++x) {
                if(arena[j + k0 - k][x] == '0') {
                    ishost[(1 << (k - j + 1)) + x * 2] = 1;
                    //cerr << "0. ishost[" << (1 << (k - j + 1)) + (x << 1) << "]=1\n";
                    if(tree[(1 << (k - j + 1)) + (x << 1)] >= j) {
                        tree[(1 << (k - j)) + x] = tree[(1 << (k - j + 1)) + (x << 1)];
                        id[(1 << (k - j)) + x] = id[(1 << (k - j + 1)) + (x << 1)];
                    } else {
                        tree[(1 << (k - j)) + x] = tree[(1 << (k - j + 1)) + (x << 1) + 1];
                        id[(1 << (k - j)) + x] = id[(1 << (k - j + 1)) + (x << 1) + 1];
                        }
                } else if(arena[j + k0 - k][x] == '1') {
                    ishost[(1 << (k - j + 1)) + x * 2 + 1] = 1;
                    //cerr << "1. ishost[" << (1 << (k - j + 1)) + (x << 1) << "]=1\n";
                    if(tree[(1 << (k - j + 1)) + (x << 1) + 1] >= j) {
                        tree[(1 << (k - j)) + x] = tree[(1 << (k - j + 1)) + (x << 1) + 1];
                        id[(1 << (k - j)) + x] = id[(1 << (k - j + 1)) + (x << 1) + 1];
                    } else {
                        tree[(1 << (k - j)) + x] = tree[(1 << (k - j + 1)) + (x << 1)];
                        id[(1 << (k - j)) + x] = id[(1 << (k - j + 1)) + (x << 1)];
                    }
                }
            }
        }
        //for(int j = 1; j < (1 << (k + 1)); ++j) cerr << tree[j] << " ";
        //cerr << endl;
        //for(int j = 1; j < (1 << (k + 1)); ++j) cerr << ishost[j] << " ";
        //cerr << endl;
        if(tree[1] != 1e18) ans[i] = id[1];
        else {
            ans[i] = id[2];
            //cerr << "Before dfs, ans[" << i << "]=" << ans[i] << endl;
            dfs(3, i);
        }
        //cerr << "ans[" << i << "]=" << ans[i] << endl;
    }
    ll ansfinal = 0ll;
    for(int i = 1; i <= m; ++i) {
        ansfinal ^= (i * ans[i]);
    }
    printf("%lld\n", ansfinal);
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}