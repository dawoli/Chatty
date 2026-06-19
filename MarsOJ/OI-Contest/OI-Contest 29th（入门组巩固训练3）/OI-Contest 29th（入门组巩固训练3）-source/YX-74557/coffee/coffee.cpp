#include <bits/stdc++.h>

using namespace std;

long long t, n, m, c[10];
string s[10][10];

long long work(long long x, long long y){
    if (y != 1){
        long long num = min(7 - y + 1, x);
        long long ans = 0;
        for (long long i = y; i <= 5; i++){
            ans += c[i];
        }
        return ans + work(x - num, 1);
    }
    long long sum = c[1] + c[2] + c[3] + c[4] + c[5];
    long long weeks = x / 7;
    long long num = sum * weeks;
    long long days = x % 7;
    for (int i = 1; i <= days; i++){
        num += c[i];
    }
    return num;
}

int main(){
    freopen("coffee.in", "r", stdin);
    freopen("coffee.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--){
        for (int i = 1; i <= 5; i++){
            c[i] = 0;
            for (int j = 1; j <= 8; j++){
                cin >> s[i][j];
                if (s[i][j] == "math"){
                    c[i]++;
                }
            }
        }
        cin >> n >> m;
        cout << work(n, m) << "\n";
    }
    return 0;
}