#include<iostream>
#include<algorithm>
#include<cstdio>
constexpr int N = 1e5+7;
using ll = long long;
ll arr[3][N];
ll dif[N];
int bst[2][N];
int cnt[3];
int id[N];
int n;
void solve(){
    std::cin>>n;
    for(int i=1;i<=n;++i){
        id[i]=i;
        for(int j=0;j<3;++j)std::cin>>arr[j][i];
    }
    ll res=0;
    for(int i=1;i<=n;++i){
        ll mx=-1,sm=-1;
        for(int j=0;j<3;++j){
            ll now=arr[j][i];
            if(now>=mx) sm = mx,mx = now, bst[1][i] = bst[0][i], bst[0][i] = j;
            else if(now>sm) sm = now, bst[1][i] = j;
        }
        res += sm;
        dif[i] = mx - sm;
        // std::cout<<"Yakumo "<<bst[0][i]<<" "<<dif[i]<<std::endl;
    }
    std::sort(id+1,id+1+n,[](const int&A,const int&B){
        return dif[A]>dif[B];
    });
    for(int i=0;i<3;++i)cnt[i]=0;
    int lim = n>>1;
    for(int i=1;i<=n;++i){
        int ID = id[i];
        // std::cout<<"Reimu "<<ID<<std::endl;
        if(cnt[bst[0][ID]] == lim)++cnt[bst[1][ID]];
        else{
            ++cnt[bst[0][ID]];
            res+=dif[ID];
        }
    }
    std::cout<<res<<"\n";
}
int main(){
    std::freopen("club.in","r",stdin);
    std::freopen("club.out","w",stdout);
    int _;
    std::cin>>_;
    while(_--)solve();
}