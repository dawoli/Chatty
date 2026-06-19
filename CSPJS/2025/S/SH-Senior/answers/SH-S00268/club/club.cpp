#include <bits/stdc++.h>
using namespace std;

void solve(){
    int ans = 0x3f3f3f3f;
    int n;
    cin >> n;
    int a[15][4], cur[15], num[4];
    memset(cur, 0, sizeof(cur));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            cin >> a[i][j];
        }
    }
    while(cur[n] <= 2){
        memset(num, 0, sizeof(num));
        cur[1]++;
        for(int i = 1; i < n; i++){
            if(cur[i] / 3 == 1){
                cur[i] = 0;
                cur[i + 1]++;
            }
        }
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += a[i][cur[i]];
            num[cur[i]]++;
            if(num[cur[i]] > n / 2){
                break;
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << "\n";
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
