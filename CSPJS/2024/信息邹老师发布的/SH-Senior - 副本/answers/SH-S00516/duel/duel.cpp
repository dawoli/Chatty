#include <bits/stdc++.h>
using namespace std;
int N;
int b[100005];

int ans = 0;
int main () {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int h;
        cin >> h;
        b[h]++;
    }
    for(int i = 1; i <= 100000; i++) {
        if(b[i]) {
            if(ans > b[i]) ans -= b[i];
            else ans = 0;
            ans += b[i]; 
        }
    }
    cout << ans;
    return 0;
}
