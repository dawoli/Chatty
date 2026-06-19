#include<bits/stdc++.h>
using namespace std;
long long T,n,m,L,V,ll,rr,mid,aa,pp,ans,num,mn1,mn2,d[100009],v[100009],a[100009],p[100009],l[100009],r[100009],id[100009];
bool cmp(const long long &aa,const long long &bb){
    return l[aa]>l[bb]||(l[aa]==l[bb]&&r[aa]<r[bb]);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
        L++;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",d+i,v+i,a+i);
            d[i]++;
        }
        for(int i=1;i<=m;i++){
            scanf("%lld",p+i);
            p[i]++;
        }
        num=ans=0;
        for(int i=1;i<=n;i++){
            l[i]=lower_bound(p+1,p+m+1,d[i])-p;
            if(l[i]>m)continue;
            if(a[i]>0){
                if(v[i]>V){
                    if(l[i]<=m)r[i]=m;
                    else r[i]=-1;
                }
                else{
                    ll=l[i];
                    rr=m;
                    pp=V*V-v[i]*v[i];
                    aa=m+1;
                    while(ll<=rr){
                        mid=(ll+rr)>>1;
                        if(2*a[i]*(p[mid]-d[i])<=pp)ll=mid+1;
                        else{
                            aa=mid;
                            rr=mid-1;
                        }
                    }
                    if(aa<=m){
                        l[i]=aa;
                        r[i]=m;
                    }
                    else r[i]=-1;
                }
            }
            else if(a[i]==0){
                if(v[i]>V){
                    r[i]=m;
                }
                else r[i]=-1;
            }
            else{
                if(v[i]<=V){
                    r[i]=-1;
                }
                else{
                    ll=l[i];
                    rr=m;
                    pp=v[i]*v[i]-V*V;
                    aa=-1;
                    a[i]=-a[i];
                    while(ll<=rr){
                        mid=(ll+rr)>>1;
                        if(2*a[i]*(p[mid]-d[i])<pp){
                            ll=mid+1;
                            aa=mid;
                        }
                        else{
                            rr=mid-1;
                        }
                    }
                    if(aa>=l[i]){
                        r[i]=aa;
                    }
                    else r[i]=-1;
                }
            }
            if(r[i]!=-1){
                l[++num]=l[i];
                r[num]=r[i];
                id[num]=num;
            }
        }
        printf("%lld ",num);
        sort(id+1,id+num+1,cmp);
        mn1=mn2=m+1;
        ans=m;
        for(int i=1;i<=num;i++){
            if(r[id[i]]>=mn1)continue;
            mn1=r[id[i]];
            if(r[id[i]]>=mn2)continue;
            ans--;
            mn2=l[id[i]];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
