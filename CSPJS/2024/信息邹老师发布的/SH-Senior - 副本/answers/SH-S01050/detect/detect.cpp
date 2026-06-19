#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,d[105000],v[105000],a[105000],p[105000];
int ll[105000],rr[105000],l[105000],r[105000],lmax[105000];
int ans1,ans2;
void solvesub(int idx) {
    if ((a[idx]<=0)&&(v[idx]<=V)) {
        ll[idx]=rr[idx]=L+1;
        return;
    }
    if (v[idx]<=V) {
        ll[idx]=d[idx]+(V*V-v[idx]*v[idx]+a[idx]*2)/(a[idx]*2);
        rr[idx]=L;
        if (ll[idx]>rr[idx]) ll[idx]=rr[idx]=L+1;
        return;
    }
    //v[idx]>V
    if (a[idx]>=0) {
        ll[idx]=d[idx];
        rr[idx]=L;
        return;
    }
    ll[idx]=d[idx];
    rr[idx]=d[idx]+(v[idx]*v[idx]-V*V-1)/(-a[idx]*2);
    if (rr[idx]>L) rr[idx]=L;
}
void solveidx(int idx) {
    if (ll[idx]==L+1) {
        //assert(rr[idx]==L+1);
        l[idx]=r[idx]=-1;
        return;
    }
    //assert(ll[idx]<=rr[idx]);
    //assert(rr[idx]<=L);
    static int cl,cr,mid,res;
    cl=1;cr=m;mid=0;res=0;
    while (cl<=cr) {
        mid=(cl+cr)/2;
        if (p[mid]>=ll[idx]) {
            res=mid;
            cr=mid-1;
        } else {
            cl=mid+1;
        }
    }
    l[idx]=res;
    cl=1;cr=m;mid=0;res=0;
    while (cl<=cr) {
        mid=(cl+cr)/2;
        if (p[mid]<=rr[idx]) {
            res=mid;
            cl=mid+1;
        } else {
            cr=mid-1;
        }
    }
    r[idx]=res;
    if ((l[idx]>r[idx])||(!l[idx])||(!r[idx])) {
        l[idx]=r[idx]=-1;
        return;
    }
    //assert(p[l[idx]]>=ll[idx]);
    //assert(p[r[idx]]<=rr[idx]);
}
int main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for (int i=1;i<=n;i++) {
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
            solvesub(i);
        }
        for (int i=1;i<=m;i++) scanf("%d",&p[i]);
        for (int i=1;i<=n;i++) {
            solveidx(i);
        }
        int nn=0;
        for (int i=1;i<=n;i++) {
            if (l[i]>=1) {
                nn++;
                l[nn]=l[i];
                r[nn]=r[i];
            }
        }
        ans1=nn;
        n=nn;
        for (int i=1;i<=m;i++) lmax[i]=0;
        for (int i=1;i<=n;i++) {
            lmax[r[i]]=max(lmax[r[i]],l[i]);
        }
        ans2=0;
        int lst=0;
        for (int i=1;i<=m;i++) {
            if (lmax[i]>lst) {
                lst=i;
                ans2++;
            }
        }
        printf("%d %d\n",ans1,m-ans2);
    }
    return 0;
}
