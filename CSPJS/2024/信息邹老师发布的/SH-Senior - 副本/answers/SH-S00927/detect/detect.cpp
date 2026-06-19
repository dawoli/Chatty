#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdio>
using namespace std;
int T,n,m,l,mx,d,v,a,cnt,p[100010]={-1},ans,ps;
double t;
pair<int,int> k,c[100010],cc[100010];
pair<int,int> calc() {
    if (a<=0&&v<=mx) return {-1,0};
    if (a>=0&&v>mx) return {l,d};
    t=d+(1.0*mx*mx-v*v)/2/a;
    if (a<0) return {min(int(ceil(t))-1,l),d};
    return {l,int(t)+1};
}
int main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while (T--) {
        cin>>n>>m>>l>>mx;
        cnt=0;
        for (int i=1;i<=n;i++) {
            cin>>d>>v>>a;
            c[i]=calc();
        }
        for (int i=1;i<=m;i++) cin>>p[i];
        for (int i=1;i<=n;i++) {
            ps=upper_bound(p+1,p+m+1,c[i].first)-p-1;
            if (ps&&p[ps]>=c[i].second) cc[++cnt]=c[i];
        }
        sort(cc+1,cc+cnt+1);
        ps=0;
        ans=0;
        for (int i=1;i<=cnt;i++) {
            if (p[ps]<cc[i].second) ans++,ps=upper_bound(p+1,p+m+1,cc[i].first)-p-1;
        }
        cout<<cnt<<' '<<m-ans<<endl;
    }
}