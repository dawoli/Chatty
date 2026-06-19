#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
int T,n,a[N];
ll f[N][2][2];
namespace BF{
    ll sum[3000][3000];
    void work(){
        for(int i = 2; i <= n ; ++ i){
            sum[i-1][i-1] = 0;
            for(int j = i; j<= n ; ++ j){
                sum[i-1][j] = sum[i-1][j-1] + ((a[j] == a[j-1]) ? a[j] : 0);
            }
        }
        for(int i = 2; i <= n ; ++ i){
            f[i][0][0] = max(f[i-1][0][0],f[i-1][0][1]) + ((a[i] == a[i-1]) ? a[i] : 0);
            f[i][1][1] = max(f[i-1][1][0],f[i-1][1][1]) + ((a[i] == a[i-1]) ? a[i] : 0);
            for(int j = 1; j < i; ++ j){
                int cnt = sum[j][i-1];
                if(a[i] == a[j-1]){
                    f[i][0][1] = max(f[i][0][1], f[j][1][0] + cnt + a[i]);
                    f[i][1][0] = max(f[i][1][0], f[j][0][1] + cnt + a[i]);
                }else{
                    f[i][0][1] = max(f[i][0][1], f[j][1][0] + cnt);
                    f[i][1][0] = max(f[i][1][0], f[j][0][1] + cnt);
                }
            }
        }
        cout << max(f[n][0][0] , max(f[n][0][1],max(f[n][1][1],f[n][1][0]))) << "\n";
    }
}
namespace DFF{
    int cur[N * 5],lst[N];
    void work(){
        for(int i = 2; i <= n ; ++ i){
            f[i][0][0] = max(f[i-1][0][0],f[i-1][0][1]) + ((a[i] == a[i-1]) ? a[i] : 0);
            f[i][1][1] = max(f[i-1][1][0],f[i-1][1][1]) + ((a[i] == a[i-1] )? a[i] : 0);
            ll cnt = 0;
            for(int j = i-1; j >=1 ; --j){
                if(j != i-1)cnt += (a[j+1] == a[j]) ? a[j] : 0;
                if(a[i] == a[j-1]){
                    f[i][0][1] = max(f[i][0][1], f[j][1][0] + cnt + a[i]);
                    f[i][1][0] = max(f[i][1][0], f[j][0][1] + cnt + a[i]);
                }else{
                    f[i][0][1] = max(f[i][0][1], f[j][1][0] + cnt);
                    f[i][1][0] = max(f[i][1][0], f[j][0][1] + cnt);
                }
            }
        }
        cout << max(f[n][0][0] , max(f[n][0][1],max(f[n][1][1],f[n][1][0]))) << "\n";
    }
    void twork(){
        for(int i = 1; i <= n ; ++ i)cur[a[i]] = 0;
        for(int i = 1; i <= n ; ++ i){
            lst[i] = cur[a[i]];
            cur[a[i]] = i;
        }
        for(int i = 2; i <= n ; ++ i){
            f[i][0][0] = max(f[i-1][0][0],f[i-1][0][1]) + ((a[i] == a[i-1]) ? a[i] : 0);
            f[i][1][1] = max(f[i-1][1][0],f[i-1][1][1]) + ((a[i] == a[i-1]) ? a[i] : 0);
            ll cnt = 0;
            for(int j = i-1; j >= max(1,lst[i]);--j){
                if(j != i-1)cnt += (a[j+1] == a[j]) ? a[j] : 0;
                if(a[i] == a[j-1]){
                    f[i][0][1] = max(f[i][0][1], f[j][1][0] + cnt + a[i]);
                    f[i][1][0] = max(f[i][1][0], f[j][0][1] + cnt + a[i]);
                }else{
                    f[i][0][1] = max(f[i][0][1], f[j][1][0] + cnt);
                    f[i][1][0] = max(f[i][1][0], f[j][0][1] + cnt);
                }
            }
        }
        cout << max(f[n][0][0] , max(f[n][0][1],max(f[n][1][1],f[n][1][0]))) << "\n";
    }
    
}
namespace EFF{
    int cur[N * 5],lst[N];
    ll sum[N];
    vector<int> pos[N * 5];
    void work(){
        sum[0] = 0;
        for(int i = 1; i <= n ; ++ i)cur[a[i]] = 0,pos[a[i]].clear();
        for(int i = 1; i <= n ; ++ i){
            sum[i] = sum[i-1] + ((a[i] == a[i-1]) ? a[i] : 0);
            lst[i] = cur[a[i]];
            pos[a[i]].push_back(i);
            cur[a[i]] = i;
        }
        for(int i = 2; i <= n ; ++ i){
            f[i][0][0] = max(f[i-1][0][0],f[i-1][0][1]) + ((a[i] == a[i-1]) ? a[i] : 0);
            f[i][1][1] = max(f[i-1][1][0],f[i-1][1][1]) + ((a[i] == a[i-1]) ? a[i] : 0);
            ll cnt = 0;
            for(int j = i-1; j >= max(1,i - 200);--j){
                if(j != i-1)cnt += (a[j+1] == a[j]) ? a[j] : 0;
                if(a[i] == a[j-1]){
                    f[i][0][1] = max(f[i][0][1], f[j][1][0] + cnt + a[i]);
                    f[i][1][0] = max(f[i][1][0], f[j][0][1] + cnt + a[i]);
                }else{
                    f[i][0][1] = max(f[i][0][1], f[j][1][0] + cnt);
                    f[i][1][0] = max(f[i][1][0], f[j][0][1] + cnt);
                }
            }
            for(int x : pos[a[i]]){
                if(x >= i-1)break;
                int lcnt = sum[i-1] - sum[x] - ((a[x+1] == a[x]) ? a[x] : 0);
                f[i][0][1] = max(f[i][0][1], f[x+1][1][0] + lcnt + a[i]);
                f[i][1][0] = max(f[i][1][0], f[x+1][0][1] + lcnt + a[i]);
            }
                
        }
        cout << max(f[n][0][0] , max(f[n][0][1],max(f[n][1][1],f[n][1][0]))) << "\n";
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> T;
    while(T--){
        int mx =  0;
        cin >> n;
        for(int i = 1; i <= n ; ++ i){
            cin >> a[i];
            mx = max(mx,a[i]);
            f[i][0][0] = f[i][0][1] = f[i][1][0] = f[i][1][1] = 0;
        }
        if(n <= 20000){
            DFF::work();
        }else if(mx <= 100)DFF::twork();
        else EFF::work();
    }
    return 0;
}