#include<bits/stdc++.h>
#define mkp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
constexpr int N=1000009;
int a[N][4],n;
vector<int> ret[N];
int calc(int u){
    int mxid=0;
    for(int i=1;i<=3;i++){
        if(a[u][i]>a[u][mxid]){
            mxid=i;
        }
    }
    int ret2=-1;
    for(int i=1;i<=3;i++){
        if(i^mxid) ret2=max(ret2,a[u][i]);
    }
    return a[u][mxid]-ret2;
}
bool cmp(int x,int y){
    return calc(x)<calc(y);
}
void solve(){
    cin>>n;
    for(int i=1;i<=3;i++) ret[i].clear();
    for(int i=1;i<=n;i++) for(int j=0;j<=3;j++) a[i][j]=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
        a[i][0]=-1;
        int k=max_element(a[i]+1,a[i]+4)-a[i];
        ret[k].push_back(i);
        ans+=a[i][k];
    }
    // cout<<ans<<"\n";
    for(int i=1;i<=3;i++){
        int sz=ret[i].size();
        if(sz<=n/2) continue;
        int mns=sz-n/2;
        sort(all(ret[i]),cmp);
        for(int j=0;j<mns;j++) ans-=calc(ret[i][j]);
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}