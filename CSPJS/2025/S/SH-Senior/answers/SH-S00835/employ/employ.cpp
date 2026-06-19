#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
bool a = 1;
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(nums[i] > 1) {
            a = 0;
        }
    }
    if(a) {
        if(m > 1 || s[0] == '0') {
            cout << 0 << '\n';
            return 0;
        }
        int ans = 1;
        for(int i = 1; i < n; i++) {
            ans *= i;
            ans %= 998244353LL;
        }
        cout << ans << '\n';
        return 0;
    }
    vector<int> perm, fin;
    for(int i = 0; i < n; i++) {
        perm.push_back(i);
    }
    fin = perm;
    int ans = 0;
    do {
        int out = 0;
        int emp = 0;
        for(int j = 0; j < n; j++) {
            if(nums[perm[j]] <= out || s[j] == '0') {
                out++;
                continue;
            }
            emp++;
        }
        if(emp >= m) {
            ans++;
        }
        next_permutation(perm.begin(), perm.end());
    }while(perm != fin);
    cout << ans << '\n';
    return 0;
}