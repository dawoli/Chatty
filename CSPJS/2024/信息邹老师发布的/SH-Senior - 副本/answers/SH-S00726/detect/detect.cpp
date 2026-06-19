#include<bits/stdc++.h>
using namespace std; const int N=100010; using ll=long long; int D[N],A[N],V0[N],p[N]; pair<int,int> c[N];
int main(){
    freopen("detect.in","r",stdin); freopen("detect.out","w",stdout);
    int T; scanf("%d",&T);
    while(T--){
        int N,n=0,m,L,V,s=0; scanf("%d%d%d%d",&N,&m,&L,&V);
        for(int i=1;i<=N;++i) scanf("%d%d%d",&D[i],&V0[i],&A[i]);
        for(int i=1;i<=m;++i) scanf("%d",&p[i]); sort(p+1,p+m+1);
        for(int i=1;i<=N;++i){
            int d=D[i],a=A[i]*2,v0=V0[i],l,r; ll x=1ll*V*V-1ll*v0*v0;
            if(a==0){
                if(v0>V) l=d,r=L;
                else l=r=L+1;
            }
            else if(a>0){
                if(v0>V) l=d,r=L;
                else l=d+x/a+1,r=L;
            }
            else{
                if(v0>V) x=-x,a=-a,l=d,r=min(0ll+L,d+(x+a-1)/a-1);
                else l=r=L+1;
            }
            //cout<<l<<" "<<r<<endl;
            l=lower_bound(p+1,p+m+1,l)-p; r=upper_bound(p+1,p+m+1,r)-1-p;
            //cout<<l<<" "<<r<<endl;
            if(l<=r) c[++n]={r,l};
        }
        sort(c+1,c+n+1);
        //for(int i=1;i<=n;++i) cout<<c[i].second<<" "<<c[i].first<<endl;
        for(int i=1,p=-1;i<=n;++i) if(c[i].second>p) p=c[i].first,++s;//,cout<<p<<endl;
        printf("%d %d\n",n,m-s);
    }
    return 0;
}