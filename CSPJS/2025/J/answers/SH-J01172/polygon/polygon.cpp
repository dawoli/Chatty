#include <bits/stdc++.h>
using namespace std;
const int N = 5005, mod = 998244353;
int n, a[N], b[N], f[N], s[N], ans;
int qpow2(int x) {
    if (x <= 1) return 1 << x;
    long long m = qpow2(x / 2), n = qpow2(x % 2);
    return m * m % mod * n % mod;
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    // freopen("polygon.err", "w", stderr);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n; for (int i = 1; i <= n; i++) cin >> a[i], b[a[i]]++;
    sort(a + 1, a + n + 1, greater<int>());
    f[0] = s[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = a[1]; j >= a[i]; j--) (f[j] += f[j - a[i]]) %= mod;
    for (int j = 1; j <= a[1]; j++) (s[j] = s[j - 1] + f[j]) %= mod;
    for (int rest = n, i = a[1]; i >= 1; i--)
        for (int j = 1; j <= b[i]; j++)
            (ans += qpow2(--rest) - s[i] + j) %= mod;
    cout << ans << endl;
    return 0;
}
/*
0. sort the array in decreasing order.
1. consider the longest stick selected, say a_{i} = l_{1}.
   then the rest sticks that can be selected is from a_{i+1} to a_{n},
2. as we want to find the possible number of cases that
    sum_{i=2}^{m} l_{i} > l{1},
   where l_{2} ~ l_{m} is the rest sticks selected,
   then the answer is all possible number of cases 2^{n-i} subtracts
   the possible number of cases that sum_{i=2}^{m} l_{i} <= l{1}.
   we can use a 01±³°ü to calculate this kind of cases,
   as we prework this case with volume a[1].
3. then we can deal with query with the longest stick selected a_{1}
   with the above algorithm. when there is duplicate length of sticks,
   the answer should be increase by the number of the sticks that have
   been calculated in order to solve the problem of the answer being
   reduced more than it should be.

time: [9:30, 10:41].
*/