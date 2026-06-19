#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
const int N = 500005;
int n, k, ans;
int a[N], s[N];
int f[N];
vector<pii> vt, chosen;
bool cmp(pii a, pii b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main() {
    freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        s[i] = s[i-1] ^ a[i];
    }
    for(int l = 1;l <= n;l++) {
        for(int r = l;r <= n;r++) {
            if((s[r] ^ s[l-1]) == k) {
                if(f[l] == 0) {
                    f[l] = r;
                    ans++;
                }
                else if(r < f[l]) {
                    f[l] = r;
                    ans++;
                }
            }
        }
    }
    if(ans == 0) {
        cout << ans;
        return 0;
    }
    int last = 1;
    for(int i = 2;i <= n;i++) {
        if(f[i] == 0) continue;
        if(f[last] >= i) {
            ans--;
        }
        else {
            last = i;
        }
    }
    cout << ans;
    return 0;
}
