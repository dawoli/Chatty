#include <bits/stdc++.h>
using namespace std;

int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, n;
string dp[(int)1e5 + 6];
vector<int> sted[10];

string& cmp(string& a, string& b) {
    if (a == "-1") return b;
    if (b == "-1") return a;
    if (a.size() < b.size()) return a;
    if (b.size() < a.size()) return b;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < b[i]) {
            return a;
        }
        if (b[i] < a[i]) {
            return b;
        }
    }
    return a;
}

string dfs(int n) {
    if (dp[n] != "-1") return dp[n];
    if (n <= 7 && n > 1) {
        char v = sted[n][0] + '0';
        if (v == '0') v = sted[n][1] + '0';
        string tmp = "";
        tmp += v;
        return dp[n] = tmp;
    }
    if (n == 1) {
        return "-1";
    }
    if (n >= 9) {
        string res = dfs(n - 7);
        if (res != "-1") {
            dp[n] = res + "8";
        }
    }
    if (n >= 8) {
        string res = dfs(n - 6);
        if (res != "-1") {
            string tmp = res + '0';
            dp[n] = cmp(dp[n], tmp);
        }
    }
    return dp[n];
    /*
    if (n >= 7) {
        string res = dfs(n - 5);
        if (res != "-1")
            return dp[n] = res + "2";
    }
    if (n >= 6) {
        string res = dfs(n - 4);
        if (res != "-1")
            return dp[n] = res + "4";
    }
    if (n >= 5) {
        string res = dfs(n - 3);
        if (res != "-1") {

        }
    }
    */
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    for (int i = 0; i< 10; i++) {
        sted[arr[i]].push_back(i);
    }
    int t;
    cin >> t;
    for (int i= 1; i <= 1e5; i++) dp[i] = "-1";
    while (t--) {
        cin >> n;
        
        cout << dfs(n) << endl;
    }
    return 0;
}
