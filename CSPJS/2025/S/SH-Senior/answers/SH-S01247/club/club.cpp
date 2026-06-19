#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+10;
int n, a[N][3], minn[N], ans;
vector<int> sk[3];

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
int t;
cin >> t;
while(t--){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        int r = max(a[i][0],max(a[i][1],a[i][2]));
        int b = min(a[i][0],min(a[i][1],a[i][2]));
        ans += r;
        if(a[i][0] == r){
            sk[0].push_back(r-a[i][1]-a[i][2]+b);
            continue;
        }
        if(a[i][1] == r){
            sk[1].push_back(r-a[i][0]-a[i][2]+b);
            continue;
        }
        if(a[i][2] == r){
            sk[2].push_back(r-a[i][1]-a[i][0]+b);
            continue;
        }
    }
    if(sk[0].size() > n/2){
        sort(sk[0].begin(),sk[0].end());
        for(int i = 0; i < sk[0].size() - (n/2); i++)
            ans -= sk[0][i];
    }
    if(sk[1].size() > n/2){
        sort(sk[1].begin(),sk[1].end());
        for(int i = 0; i < sk[1].size() - (n/2); i++)
            ans -= sk[1][i];
    }
    if(sk[2].size() > n/2){
        sort(sk[2].begin(),sk[2].end());
        for(int i = 0; i < sk[2].size() - (n/2); i++)
            ans -= sk[2][i];
    }
    cout << ans << "\n";
    sk[0].clear();
    sk[1].clear();
    sk[2].clear();
    ans = 0;
}
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/