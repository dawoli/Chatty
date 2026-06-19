#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Node { int p,q,r,id,v; }a[N],b[N];
bool cmp(Node a,Node b) { return a.v<b.v; }
void solve() {
    int n,cnt1=0,cnt2=0,cnt3=0,sum=0; cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i].p>>a[i].q>>a[i].r;
        int t=max({a[i].p,a[i].q,a[i].r}); sum+=t;
        if(t==a[i].p) a[i].v=min(a[i].p-a[i].q,a[i].p-a[i].r),cnt1++,a[i].id=1;
        else if(t==a[i].q) a[i].v=min(a[i].q-a[i].p,a[i].q-a[i].r),cnt2++,a[i].id=2;
        else a[i].v=min(a[i].r-a[i].p,a[i].r-a[i].q),cnt3++,a[i].id=3;
    }
    int t=max({cnt1,cnt2,cnt3});
    if(t<=(n>>1)) {
        //cout<<t<<'\n';
        cout<<sum<<'\n';
        return;
    }
    //cout<<"Check\n";
    //cout<<cnt1<<' '<<cnt2<<' '<<cnt3<<' '<<t<<'\n';
    int tot=0;
    if(cnt1==t) { for(int i=1;i<=n;i++) if(a[i].id==1) b[++tot]=a[i]; }
    else if(cnt2==t) { for(int i=1;i<=n;i++) if(a[i].id==2) b[++tot]=a[i]; }
    else for(int i=1;i<=n;i++) { if(a[i].id==3) b[++tot]=a[i]; }
    //cout<<tot<<'\n';
    sort(b+1,b+tot+1,cmp); int res=tot;
    //for(int i=1;i<=tot;i++) cout<<b[i].p<<' '<<b[i].q<<' '<<b[i].r<<' '<<b[i].v<<'\n';
    for(int i=1;i<=tot;i++) {
        res--,sum-=b[i].v;
        if(res==(n>>1)) break;
    }
    cout<<sum<<'\n';
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
