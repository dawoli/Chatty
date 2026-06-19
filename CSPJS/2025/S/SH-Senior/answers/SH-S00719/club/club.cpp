#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
struct pers {
    long long a, b, c;
}arr[N];
int acnt = 0, bcnt = 0, ccnt = 0;
vector<int> ca, cb, cc;
bool cz[N];

bool cmp1(int a, int b) {
    int mxa = max({arr[a].a, arr[a].b, arr[a].c});
    int mxb = max({arr[b].a, arr[b].b, arr[b].c});
    return min(mxa - arr[a].b, mxa - arr[a].c) > min(mxb - arr[b].b, mxb - arr[b].c);
    // return max(arr[a].b, arr[a].c) > max(arr[b].b, arr[b].c);
}

bool cmp2(int a, int b) {
    int mxa = max({arr[a].a, arr[a].b, arr[a].c});
    int mxb = max({arr[b].a, arr[b].b, arr[b].c});
    return min(mxa - arr[a].a, mxa - arr[a].c) > min(mxb - arr[b].a, mxb - arr[b].c);
    // return max(arr[a].a, arr[a].c) > max(arr[b].a, arr[b].c);
}

bool cmp3(int a, int b) {
    int mxa = max({arr[a].a, arr[a].b, arr[a].c});
    int mxb = max({arr[b].a, arr[b].b, arr[b].c});
    return min(mxa - arr[a].a, mxa - arr[a].b) > min(mxb - arr[b].a, mxb - arr[b].b);
    // return
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        ca.clear(); cb.clear(); cc.clear();
        acnt = bcnt = ccnt = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cz[i] = 0;
            cin >> arr[i].a >> arr[i].b >> arr[i].c;
            int mx = max({arr[i].a, arr[i].b, arr[i].c});
            if (mx == arr[i].a) {
                ca.push_back(i);
                acnt++;
                continue;
            }
            if (mx == arr[i].b) {
                cb.push_back(i);
                bcnt++;
                continue;
            }
            if (mx == arr[i].c) {
                cc.push_back(i);
                ccnt++;
                continue;
            }
        }
        if (acnt > n / 2) {
            long long ans = 0;
            sort(ca.begin(), ca.end(), cmp1);
            int lena = ca.size();
            for (int i = 0; i < n / 2; i++) {
                int v = ca[i];
                ans += arr[v].a;
                cz[ca[i]] = 1;
            }
            for (int i = 1; i <= n; i++) {
                if (cz[i]) continue;
                ans += max(arr[i].b, arr[i].c);
            }
            cout << ans << '\n';
            continue;
        }
        if (bcnt > n / 2) {
            long long ans = 0;
            sort(cb.begin(), cb.end(), cmp2);
            int lenb = cb.size();
            for (int i = 0; i < n / 2; i++) {
                int v = cb[i];
                cz[cb[i]] = 1;
                ans += arr[v].b;
            }
            for (int i = 1; i <= n; i++) {
                if (cz[i]) continue;
                ans += max(arr[i].a, arr[i].c);
            }
            cout << ans << '\n';
            continue;
        }
        if (ccnt > n / 2) {
            long long ans = 0;
            sort(cc.begin(), cc.end(), cmp3);
            int lenc = cc.size();
            for (int i = 0; i < n / 2; i++) {
                int v = cc[i];
                ans += arr[v].c;
                cz[cc[i]] = 1;
            }
            for (int i = 1; i <= n; i++) {
                if (cz[i]) continue;
                ans += max(arr[i].a, arr[i].b);
            }
            cout << ans << '\n';
            continue;
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += max({arr[i].a, arr[i].b, arr[i].c});
        }
        cout << ans << '\n';
    }
}