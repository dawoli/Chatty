#include <bits/stdc++.h>
using namespace std;

int ma[11] = {6,2,5,5,4,5,6,3,7,6};
long long ans=-1;

void dfs(long long nbefore,long long nafter, bool canzero) {
    if (nbefore<0) return;
    if (nbefore==0) {
        if (ans!=-1) {
            if (nafter<ans) ans=nafter;
        }
        if (ans==-1) ans=nafter;
    }
    for (int i=0;i<=9;i++) {
        if (canzero==false && i==0) continue;
        dfs(nbefore-ma[i], nafter*10+i, true);
    }
}

long long n,t;

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    for (long long i=1; i<=t; i++) {
        ans=-1;
        cin >> n;
        dfs(n, 0, false);
        cout << ans << endl;
    }
    return 0;
}
