#include<bits/stdc++.h>
using namespace std;
long long T,n,m,tmp1,tmp2,tmp3,tmp4,mx,a[1000009],b[1000009],c[1000009];
struct seg{
    long long v[1000009],lazy1[1000009],lazy2[1000009];
    void update(int rt,int l,int r,int xx,long long yy){
        if(l==r){
            v[rt]=max(v[rt],yy);
            return;
        }
        int mid=(l+r)>>1;
        if(lazy1[rt]){
            lazy1[rt<<1]=lazy1[rt<<1|1]=1;
            lazy2[rt<<1]=lazy2[rt<<1|1]=0;
            v[rt<<1]=v[rt<<1|1]=0xc0c0c0c0c0c0c0c0;
            lazy1[rt]=0;
        }
        if(lazy2[rt]){
            lazy2[rt<<1]+=lazy2[rt];
            lazy2[rt<<1|1]+=lazy2[rt];
            v[rt<<1]+=lazy2[rt];
            v[rt<<1|1]+=lazy2[rt];
            lazy2[rt]=0;
        }
        if(xx<=mid)update(rt<<1,l,mid,xx,yy);
        else update(rt<<1|1,mid+1,r,xx,yy);
        v[rt]=max(v[rt<<1],v[rt<<1|1]);
        return;
    }
    long long query(int rt,int l,int r,int xx){
        if(l==r){
            return v[rt];
        }
        int mid=(l+r)>>1;
        if(lazy1[rt]){
            lazy1[rt<<1]=lazy1[rt<<1|1]=1;
            lazy2[rt<<1]=lazy2[rt<<1|1]=0;
            v[rt<<1]=v[rt<<1|1]=0xc0c0c0c0c0c0c0c0;
            lazy1[rt]=0;
        }
        if(lazy2[rt]){
            lazy2[rt<<1]+=lazy2[rt];
            lazy2[rt<<1|1]+=lazy2[rt];
            v[rt<<1]+=lazy2[rt];
            v[rt<<1|1]+=lazy2[rt];
            lazy2[rt]=0;
        }
        if(xx<=mid)return query(rt<<1,l,mid,xx);
        else return query(rt<<1|1,mid+1,r,xx);
    }

}tr[2];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        mx=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",a+i);
            mx=max(mx,a[i]);
        }
        for(int i=1;i<=mx;i++)b[i]=0;
        m=1;
        for(int i=1;i<=n;i++){
            if(!b[a[i]]){
                b[a[i]]=++m;
            }
            c[i]=b[a[i]];
        }
        tr[0].lazy1[1]=tr[1].lazy1[1]=1;
        tr[0].lazy2[1]=tr[1].lazy2[1]=0;
        tr[0].v[1]=tr[1].v[1]=0xc0c0c0c0c0c0c0c0;
        tr[0].update(1,1,m,c[1],0);
//        cout<<a[1]<<" "<<a[2]<<endl;
        if(a[1]!=a[2])tr[1].update(1,1,m,1,0);
        else tr[1].update(1,1,m,1,a[1]);
//        cout<<tr[0].v[1]<<" "<<tr[1].v[1]<<endl;
        mx=max(a[1],a[2]);
        for(int i=3;i<=n;i++){
            tmp1=tr[0].v[1];
            tmp2=tr[0].query(1,1,m,c[i]);
            tmp3=tr[1].v[1];
            tmp4=tr[1].query(1,1,m,c[i]);
//            cout<<i<<" "<<tmp1<<" "<<tmp2<<" "<<tmp3<<" "<<tmp4<<endl;
            mx=max(mx,c[i]);
//            cout<<a[i]<<" "<<a[i-1]<<endl;
            if(a[i]==a[i-1]){
                tr[0].lazy2[1]+=a[i];
                tr[1].lazy2[1]+=a[i];
                tr[0].v[1]+=a[i];
                tr[1].v[1]+=a[i];
            }
//        cout<<tr[0].v[1]<<" "<<tr[1].v[1]<<endl;
            tr[0].update(1,1,m,c[i-1],max(tmp3,tmp4+a[i]));
            tr[1].update(1,1,m,c[i-1],max(tmp1,tmp2+a[i]));
//        cout<<tr[0].v[1]<<" "<<tr[1].v[1]<<endl;
        }
        printf("%lld\n",max(tr[0].v[1],tr[1].v[1]));
    }
    return 0;
}
