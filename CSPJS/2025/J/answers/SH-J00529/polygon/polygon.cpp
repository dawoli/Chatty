#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
int n;

const int N = 5005;
int arr[N];

uint64_t ans = 0;

vector<int> stk;

void dfs(int x) {
    if (x == n + 1) {
        int n_max = arr[stk.back()];
        int n_total = 0;

        for (auto ix : stk) {
            n_total += arr[ix];
        }

        if (n_total > (n_max * 2)) {
            ans++;
        }
        return;
    }

    stk.push_back(x);
    dfs(x + 1);
    stk.pop_back();
    dfs(x + 1);
}

int main() {
    ifstream in("polygon.in");
    ofstream out("polygon.out");

    in >> n;

    for (int i = 1; i <= n; ++i) {
        in >> arr[i];
    }

    sort(arr, arr + n);
    
    dfs(1);

    out << (ans % MOD) << endl;

}