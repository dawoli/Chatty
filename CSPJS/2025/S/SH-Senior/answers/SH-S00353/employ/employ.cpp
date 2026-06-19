#include<bits/stdc++.h>
using namespace std;

const int MAXN=505;
const long long mod=998244353;
int n, m;
string s;
int c[MAXN];
bool vis[MAXN];
int order[MAXN];
long long ans;
long long dfs(int pos) {
    if (pos==n+1) {
        int pre=0;
        int ans=0;
        for (int i=1; i<=n; i++) {
            if (s[i]=='0'||pre>=c[order[i]]) pre++;
            else ans++;
        }
        if (ans>=m) return 1;
        else return 0;
    }
    long long ret=0;
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            vis[i]=true;
            order[pos]=i;
            (ret+=dfs(pos+1))%=mod;
            vis[i]=false;
        }
    }
    return ret;
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    cin >> s;
    for (int i=1; i<=n; i++) cin >> c[i];
    ans=dfs(0);
    cout << ans;
}
