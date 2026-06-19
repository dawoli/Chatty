#include <bits/stdc++.h>

using namespace std;
const int Maxn = 1e5 + 5;
int n;
int r[Maxn];
int ans;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin>>n;
    int x = 0, maxx = 0;
    for (int i = 1; i <= n; i++){
        cin>>x;
        maxx = max(x, maxx);
        r[x]++;
    }
    ans = n;
    int temp = 0;
    // cout<<maxx<<endl;
    for (int i = 1; i <= maxx; i++){
        if (r[i]){
            // cout<<r[i]<<endl;
            if (temp == 0){
                temp += r[i];
            }
            else{
                ans -= min(temp, r[i]);
                temp = temp - min(temp, r[i]) + r[i];
            }
            // cout<<i<<' '<< temp<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
