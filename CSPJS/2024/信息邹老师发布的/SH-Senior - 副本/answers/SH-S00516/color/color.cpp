#include <bits/stdc++.h>
using namespace std;
int T;
int N;
int a[10005];
bool b[10005];
int fans = 0;
void dfs(int step) {
    if(step == N + 1) {
        int ans = 0;
        for(int i = 2; i <= N; i++) {
            for(int j = i - 1; j > 0; j--) {
                if(b[i] == b[j]) {
                    if(a[i] == a[j])ans += a[i];
                    break;
                }
            }
        }
        fans = max(fans, ans);
        return;
    }
    b[step] = 0;
    dfs(step + 1);
    b[step]  = 1;
    dfs(step + 1);
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        fans = 0;
        dfs(1);
        cout << fans;
    }
    return 0;
}
