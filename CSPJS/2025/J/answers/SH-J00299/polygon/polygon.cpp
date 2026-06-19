#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 10005;
int n;
ll sum;
int cnt=0;
ll maxx = -0x3f3f3f3f;
ll len[N];
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;

    for (int i = 1; i<= n; i++) {
        cin >> len[i];
    }
    for (int i = 1; i<= n; i ++) {
        sum = sum + len[i];
        if (maxx < len[i]) maxx = len[i];
    }
    for (int i = 1; i<=n; i++) {
        for (int i = 1; i<= n; i ++) {
            sum = sum + len[i];
            if (maxx < len[i]) maxx = len[i];
        }
        for (int j = i; j<n; j++) {
            if (sum > 2*maxx) {
                cnt ++;
            }
        }

    }
    cout << cnt-1 << endl;
    return 0;

}
