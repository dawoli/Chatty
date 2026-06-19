#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;
const int N = 510;
int n, m, s[N], c[N], f[2][N][N], od, nw, sum[N], sums[N], J[N], invJ[N];

string sx;

inline int qpow(int x,int y){
    int res = 1;
    while(y){
        if(y&1) res = res*x%mod;
        x = x*x%mod;
        y >>= 1;
    }
    return res;
}

int C(int x,int y){
    return J[x]*invJ[x-y]%mod*invJ[y]%mod;
}

bool flag1 = true;
int p[N];

void solve10(){
    int ans = 0;
    for(int i = 1; i <= n; i++) p[i] = i;
    do{
        int now = 0;
        for(int i = 1; i <= n; i++){
            if(i-1-now < c[p[i]] && s[i] == 1){
                ++now;
            }
        }
        ans += (now>=m);
    }while(next_permutation(p+1,p+n+1));
    cout << ans << "\n";
}

void solve(){
    
    nw = 1;
    for(int i = 0; i <= n-m; i++)
        f[nw][0][i] = 1;
    for(int i = n; i >= 1; i--){
        swap(od,nw);
        for(int j = 0; j <= n-i+1; j++){
            for(int k = 0; k <= n-m; k++){
                f[nw][j][k] = 0;
                int s2 = i-(sums[k]-j);
                if(sums[k] < j) continue;
                if(s2 < 0) continue;
                for(int t = 0; t <= sum[k+1]; t++){
                    if(j >= 1 && j+t-1 <= n-i){
                        f[nw][j][k] = (f[nw][j][k]+f[od][j+t-1][k+1]*C(j+t-1,t)%mod*J[sum[k+1]]%mod*invJ[sum[k+1]-t])%mod;
                    }
                    if(s[i] == 0 && j+t <= n-i){
                        f[nw][j][k] = (f[nw][j][k]+f[od][j+t][k+1]*C(j+t,t)%mod*J[sum[k+1]]%mod*invJ[sum[k+1]-t]%mod*s2)%mod;
                    }
                }
                if(s[i] == 1){
                    f[nw][j][k] = (f[nw][j][k]+f[od][j][k]*s2)%mod;
                }
            }
        }
    }
    cout << f[nw][sum[0]][0]*J[sum[0]]%mod << "\n";
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> sx;
    for(int i = 1; i <= n; i++){
        s[i] = sx[i-1]-'0';
        if(s[i] != 1) flag1 = false;
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        sum[c[i]]++;
    }
    J[0] = 1;

    for(int i = 1; i <= n; i++) J[i] = J[i-1]*i%mod;
    invJ[n] = qpow(J[n],mod-2);
    for(int i = n-1; i >= 0; i--) invJ[i] = invJ[i+1]*(i+1)%mod;

    sums[0] = sum[0];
    for(int i = 1; i <= n; i++)
        sums[i] = sums[i-1] + sum[c[i]];
    if(m == n){
        if(flag1 && sum[0] == 0) cout << J[n] << "\n";
        else cout << 0 << "\n";
        return 0;
    }
    if(n <= 10){
        solve10();
        return 0;
    }
    solve();
}
/*
f[i][j][k] -> 目前是从n到i第i位，i已经选完,此前仍然未分配的失败的面试共j个，此前填0~k都一定失败，情况总数
由于我们确定了第i位此时分配的是k+1
Case1时
分配前总共有 Si (0~k+1) 个一定失败的数，共j+t-1个未分配的失败的面试
Case2时
分配前总共有 Si (0~k+1) 个一定失败的数，共j+t个未分配的失败的面试，
分配后总共有 Si (0~k) 个一定失败的数，共j个未分配的失败的面试，还有s[k+1]-t个可能成功的面试，共S2 = s(0~k)+s[k+1]-t个，则此时由于填的并非失败的数，则共
i-S2个数
Case3时 不需要分配 仅需知道剩些啥
S2 = s(0~k)-j
仍然i-s2

f[i-1][j][k] = St(0~sum[k]) f[i][j+t-1][k+1]*C(j+t,t)*C(s[k],t) (i == 1 || i == 0) 即当前失败了并且填的是目前一定失败的
f[i-1][j][k] = St(0~sum[k]) f[i][j+t][k+1]*C(j+t,t)*C(s[k],t)*(i-S2) (i == 0) 即当前失败了并且填的不是目前一定失败的
f[i-1][j][k] = f[i][j][k] 即当前胜利了并且填的不是目前一定胜利的\
对于初始状态 显然 至多是0~n-m不能填，即我们已经fail了n-m次,说明win了m次
555555调不出来
或许是假了吧
5555
假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了
假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了假了
*/