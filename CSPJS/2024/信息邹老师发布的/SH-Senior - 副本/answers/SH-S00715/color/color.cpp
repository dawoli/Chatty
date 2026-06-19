/*
首先,连续的颜色块可以合并为1个
合并之后
猜想:存在最优方案满足任意发挥作用的时刻两个栈中的元素相邻
证明显然
f[i]表示当前第i个数和第i-1个数分别是两个栈的顶的最大收益
t[i]表示i后面第一个和i相同的数的位置
加入了i+1
1.都没用f[i]->f[i+1]
2.b[i-1]派上用处 f[i]+b[i-1]->f[t[i-1]]
3.b[i]派上用处 f[i]+b[i]->f[t[i]]

3 5 2 5 1 2 1 4
为什么今天的比赛比CSP-J模拟赛还要简单?我不会做错模拟赛了吧
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b)for(ll i=(a);i<=(b);i++)
#define rrep(i, a, b) for(ll i=(a);i>=(b);i--)
const ll N=2e5+9, SIZE=1e6+9;
ll T;
ll n, a[N];
ll pos[SIZE];//pos[i]表示上一个颜色i出现的位置
ll t[N];//t[i]表示i后面第一个和i相同的数的位置,t[i]为0表示i后面没有和i相同的位置了
ll f[N];
ll b[N];//b是真正的数组
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> n;
        ll maxa=0;
        ll nN=0, ans=0;
        rep(i, 1, n){
            cin >> a[i];
            if(a[i]==a[i-1]){ans+=a[i];continue;}
            b[++nN]=a[i];
            maxa=max(maxa, a[i]);
        }
        rrep(i, nN, 1){
            t[i]=pos[b[i]];
            pos[b[i]]=i;
            // cout << i << ' ' << t[i] << endl;
        }
        fill(f, f+n+5, 0);
        f[1]=0;
        f[2]=0;
        rep(i, 2, nN){
            f[i+1]=max(f[i+1], f[i]);
            if(t[i-1]){
                f[t[i-1]]=max(f[t[i-1]], f[i]+b[i-1]);
            }
            if(t[i]){
                f[t[i]]=max(f[t[i]], f[i]+b[i]);
            }
            // cout << i << ' ' << f[i] << endl;
        }
        cout << f[nN]+ans << endl;
        fill(pos, pos+maxa+5, 0);
        fill(t, t+n+5, 0);
    }
    return 0;
}