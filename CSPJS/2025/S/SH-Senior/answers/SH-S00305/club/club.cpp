#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
typedef pair<int,int> pii;
int T;
int n,a[N][5],m;
pii p[N][5];
int cnt[5];
vector<int> upds;
void work(){
    memset(cnt,0,sizeof cnt);
    cin >> n;
    m = (n / 2);
    for(int i = 1; i <= n ; ++ i)
        for(int j = 1; j <= 3 ; ++ j)cin >> a[i][j],p[i][j] = {a[i][j],j};
    for(int i = 1; i <= n ; ++ i)sort(p[i]+1,p[i]+4);
    ll res = 0;
    for(int i = 1; i <= n ; ++ i){
        cnt[p[i][3].second]++;
        res += p[i][3].first;
    }
    int k = 0;
    for(int i = 1; i <= 3 ; ++ i)if(cnt[i] > m)k = i;
    if(k == 0){
        cout << res << "\n";
        return;
    }
    upds.clear();
    for(int i = 1; i <= n ; ++ i){
        if(p[i][3].second == k){
            upds.push_back(p[i][3].first - p[i][2].first);
        }
    }
    sort(upds.begin(),upds.end());
    for(int i = 0; i < (cnt[k] - m); ++ i){
        res -= upds[i];
    }
    cout << res << "\n";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> T;
    while(T--)work();
    return 0;
}