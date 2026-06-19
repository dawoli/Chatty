#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N = 1e5+5;
ll aa[N],c[N];
ll a[N];
const int K = 33;
string d[K];
int n,m,k;

ll X[4];

vector<int> res[K];
namespace A{
void solve(){
    for(int i=1;i<=k;i++){
        res[i].clear();
        res[i].push_back(0);
        for(int j=0;j<d[i].size();j++){
            int dx = d[i][j]-'0';
            int p = a[res[i-1][j*2+dx+1]];
            if(p>=i)res[i].push_back(res[i-1][j*2+dx+1]);
            else    res[i].push_back(res[i-1][j*2+2-dx]);
        }
    }

    ll ans = 0;
    for(ll i=1;i<=m;i++){
        ans ^= i*res[__lg(c[i])][1];
//        cout << "res= " << res[__lg(c[i])][1] << '\n';
    }
    cout << ans << '\n';
}
};

namespace SMALL{

int x[10];
int calc(int len){
    for(int i=1;i<=__lg(len);i++){
        res[i].clear();
        res[i].push_back(0);
        for(int j=0;j<d[i].size();j++){
            int dx = d[i][j]-'0';
            int p = x[res[i-1][j*2+dx+1]];
            if(p>=i)res[i].push_back(res[i-1][j*2+dx+1]);
            else    res[i].push_back(res[i-1][j*2+2-dx]);
        }
    }
    return res[__lg(len)][1];
}
bool ok[N];
int goal;
void dfs(int now){
    if(now==goal+1){
        ok[calc(goal)]=1;
        return;
    }
    for(int i=0;i<=3;i++){
        x[now] = i;
        dfs(now+1);
    }
}

int getnext(int p){
    if(__builtin_popcount(p)==1)return p;
    return 2<<__lg(p);
}

void solve(){

    ll ans = 0;
    for(ll gg=1;gg<=m;gg++){
        goal = getnext(c[gg]);
        for(int i=1;i<=c[gg];i++)x[i]=a[i];
        for(int i=1;i<=(1<<k);i++)ok[i]=0;
        dfs(c[gg]+1);
        ll res = 0;
        for(int i=1;i<=(1<<k);i++)if(ok[i])res+=i;
        ans ^= gg*res;
//        cout << c[gg] <<' '<< res << '\n';
//        cout << "res= " << res[__lg(c[i])][1] << '\n';
    }

    cout << ans << '\n';
}
};

int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=m;i++)cin>>c[i];

    if(__builtin_popcount(n)==1)k=__lg(n);
    else k=__lg(n)+1;
    for(int i=1;i<=k;i++)cin>>d[i];

    for(int i=0;i<=(1<<k);i++)res[0].push_back(i);

    bool isA=1;
    for(int i=1;i<=m;i++){
        if(__builtin_popcount(c[i])>1)isA=0;
    }

    int T;cin>>T;
    while(T--){
        for(int i=0;i<4;i++)cin>>X[i];
        for(int i=1;i<=n;i++)a[i]=aa[i]^X[i%4];

        if(isA){
            A::solve();
            continue;
        }
        if(n<=8)SMALL::solve();
    }
    return 0;
}
