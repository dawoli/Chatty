#include<bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
using namespace std;

namespace AugustLight {
    const int MAXN = 1e5 + 5;

    int n;
    int a[MAXN][3];
    int mx[MAXN];

    int argmax(int p[]) {
        if (p[0] >= p[1] and p[0] >= p[2])
            return 0;
        if (p[1] >= p[0] and p[1] >= p[2])
            return 1;
        return 2;
    }
    
    int Main() {
        cin >> n;
        rep(i, 1, n)
            rep(j, 0, 2)
                cin >> a[i][j];
        
        int cnt[3];
        cnt[0] = cnt[1] = cnt[2] = 0;
        rep(i, 1, n) {
            mx[i] = argmax(a[i]);
            cnt[mx[i]]++;
        }

        int ans = 0;
        rep(i, 1, n)
            ans += a[i][mx[i]];

        if (max({cnt[0], cnt[1], cnt[2]}) <= n / 2) {
            return ans;
        }
        int gr = argmax(cnt); // greatest index
        vector<int> vec;
        rep(i, 1, n) if (mx[i] == gr) {
            int d = 2e4;
            rep(j, 0, 2) if (j != gr)
                d = min(d, a[i][gr] - a[i][j]);
            vec.emplace_back(d);
        }
        sort(vec.begin(), vec.end());
        rep(x, 0, cnt[gr] - n / 2 - 1)
            ans -= vec[x];
        return ans;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T; cin >> T; while (T--) {
        cout << AugustLight::Main() << '\n';
    }
    return 0;
}