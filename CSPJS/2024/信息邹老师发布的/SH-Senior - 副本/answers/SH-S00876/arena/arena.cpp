#include<bits/stdc++.h>
using namespace std;
long long n,m,T,N,M,K,KKK,X[9],num,rtn,a[200009],b[200009],c[200009],d[200009],e[200009],f[200009],g[200009],h[200009],p[200009],q[200009],ans[200009];
char s[200009];
void build(int rt,int l,int r){
//    if(l==1)cout<<rt<<" "<<l<<" "<<r<<" "<<K<<endl;
//    cout<<rt<<" "<<f[rt]<<endl;
    if(l>n)return;
    if(l==r){
        g[rt]=l;
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    if(r>n)return;
    if(f[rt]){
        if(a[g[rt<<1|1]]>=h[rt])g[rt]=g[rt<<1|1];
        else g[rt]=g[rt<<1];
    }
    else{
        if(a[g[rt<<1]]>=h[rt])g[rt]=g[rt<<1];
        else g[rt]=g[rt<<1|1];
    }
}
void query(int rt,int l,int r,int ll){
    p[rt]=q[rt]=0;
    if(l==r){
//            cout<<l<<" "<<r<<" "<<rt<<" "<<p[rt]<<" "<<q[rt]<<endl;
        if(l<=ll)p[rt]=l;
        else q[rt]=l;
        return;
    }
    if(r<=ll){
        p[rt]=g[rt];
        return;
    }
    if(l>ll){
        q[rt]=(r+l)*(r-l+1)/2;
        return;
    }
    int mid=(l+r)>>1;
    if(ll<mid){
        query(rt<<1,l,mid,ll);
        long long tmp=1ll*(r+mid+1)*(r-mid)/2;
        if(f[rt]){
            q[rt]=q[rt<<1]+tmp;
            p[rt]=p[rt<<1];
        }
        else{
//                cout<<rt<<" "<<l<<" "<<r<<" "<<q[rt<<1]<<" "<<q[rt<<1|1]<<endl;
            if(q[rt<<1])q[rt]=q[rt<<1]+tmp;
            if(a[p[rt<<1]]>=h[rt])p[rt]=p[rt<<1];
            else {
                q[rt]=q[rt<<1]+tmp;
            }
//            cout<<rt<<" "<<l<<" "<<r<<" "<<p[rt]<<" "<<q[rt]<<endl;
        }
    }
    else{
        query(rt<<1|1,mid+1,r,ll);
        if(f[rt]){
            q[rt]=q[rt<<1|1];
            if(a[p[rt<<1|1]]>=h[rt]){
                if(!q[rt<<1|1]||a[g[rt<<1]]<a[p[rt<<1|1]])p[rt]=p[rt<<1|1];
                else if(a[p[rt<<1|1]]>=K){
                    q[rt]+=p[rt<<1|1];
                    p[rt]=g[rt<<1];
                }
                else{
                    p[rt]=g[rt<<1];
                }
            }
            else p[rt]=g[rt<<1];
        }
        else{
//                cout<<rt<<" "<<l<<" "<<r<<" "<<a[p[rt<<1]]<<" "<<h[rt]<<" "<<" "<<p[rt<<1]<<endl;
            if(a[g[rt<<1]]>=h[rt])p[rt]=g[rt<<1];
            else {
                p[rt]=p[rt<<1|1];
                q[rt]=q[rt<<1|1];
            }
//            cout<<rt<<" "<<l<<" "<<r<<" "<<p[rt]<<" "<<q[rt]<<endl;
        }
    }
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    N=1;
    K=0;
    while(N<n){
        K++;
        N<<=1;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",e+i);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",c+i);
        b[i]=c[i];
    }
    sort(b+1,b+m+1);
    M=unique(b+1,b+m+1)-b-1;
    for(int i=1;i<=M;i++){
        for(int j=0;j<=K;j++){
            if((1<<j)>=b[i]){
                d[i]=j;
                break;
            }
        }
    }
    num=N;
    for(int i=1;i<=K;i++){
        scanf("%s",s+1);
        for(int j=(1<<(K-i));j;j--){
            f[--num]=s[j]-'0';
            h[num]=i;
        }
    }
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",X+0,X+1,X+2,X+3);
        for(int i=1;i<=n;i++){
            a[i]=e[i]^X[i%4];
        }
        build(1,1,N);
        for(int i=1;i<=M;i++){
            long long tmp=(1<<(K-d[i]));
            KKK=d[i];
            query(tmp,1,(1<<d[i]),b[i]);
            ans[b[i]]=p[tmp]+q[tmp];
//            cout<<b[i]<<" "<<p[tmp]<<" "<<q[tmp]<<endl;
        }
        rtn=0;
//        for(int long long i=1;i<=m;i++){
//            for(int j=0;j<=K;j++){
//                if((1<<j)>=c[i]){
//                    long long tmp=1<<(K-j);
//                    query(tmp,1,1<<j,c[i]);
//                    ans[i]=p[tmp]+q[tmp];
//                    break;
//                }
//            }
//            rtn^=i*ans[i];
//        }
        for(long long i=1;i<=m;i++){
            rtn^=1ll*i*ans[c[i]];
//        cout<<ans[c[i]]<<endl;
        }
        printf("%lld\n",rtn);
    }
    return 0;
}
