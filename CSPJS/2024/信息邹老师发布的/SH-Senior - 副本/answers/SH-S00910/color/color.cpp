#include<bits/stdc++.h>
#define ls(u) ((u)*2)
#define rs(u) ((u)*2+1)

using namespace std;
const long long N=1e6+9;
long long t,n,a[N],f[N];
void solvedp(){
    for(long long i=0;i<=n;i++) for(long long j=0;j<=n;j++) f[j]=0;
    long long ans=0;
    for(long long i=1;i<=n;i++){
        for(long long j=0;j<i-1;j++){
            f[i-1]=max(f[i-1],f[j]+(a[i]==a[j]?a[i]:0));
        }
        // for(long long j=0;j<i;j++) cout<<f[j]<<" ";
        // cout<<"\n";
        for(long long j=0;j<i-1;j++){
            f[j]=max(f[j],f[j]+(a[i]==a[i-1]?a[i]:0));
        }
        // for(long long j=0;j<i;j++) cout<<f[j]<<" ";
        // cout<<"\n";
    }
    for(long long i=0;i<=n;i++) ans=max(ans,f[i]);
    cout<<ans<<"\n";
}
long long fle[N],nnum[N],rfle[N];
struct Segment{
    long long l,r,val,lz;
} seg[N];
void push_down(long long u){
    seg[u].val+=seg[u].lz;
    // cout<<u<<" "<<seg[u].val<<" "<<seg[u].lz<<"\n";
    if(seg[u].l==seg[u].r){
        seg[u].lz=0;
        return;
    }
    seg[ls(u)].lz+=seg[u].lz;
    seg[rs(u)].lz+=seg[u].lz;
    // cout<<seg[u].lz<<" "<<ls(u)<<" "<<rs(u)<<"\n";
    seg[u].lz=0;
}
long long que(long long u,long long l,long long r){
    push_down(u);
    if(seg[u].r<l||seg[u].l>r) return 0;
    if(seg[u].r<=r&&seg[u].l>=l) return seg[u].val;
    return max(que(ls(u),l,r),que(rs(u),l,r));
}
void build_seg(long long u,long long l,long long r){
    long long mid=(l+r)/2;
    seg[u]=(Segment){l,r,0,0};
    if(l==r) return;
    build_seg(ls(u),l,mid);
    build_seg(rs(u),mid+1,r);
}
void upd(long long u,long long v,long long val){
    push_down(u);
    if(seg[u].l==seg[u].r){
        seg[u].val=max(val,seg[u].val);
        return;
    }
    if(seg[ls(u)].r>=v) upd(ls(u),v,val);
    else upd(rs(u),v,val);
    seg[u].val=max(seg[ls(u)].val+seg[ls(u)].lz,seg[rs(u)].val+seg[rs(u)].lz);
}
void add(long long u,long long l,long long r,long long dlt){
    if(seg[u].r<l||seg[u].l>r) return;
    if(seg[u].r<=r&&seg[u].l>=l){
        seg[u].lz+=dlt;
        // cout<<u<<"LZ"<<dlt<<" "<<seg[u].lz<<"\n";
        return;
    }
    add(ls(u),l,r,dlt);
    add(rs(u),l,r,dlt);
    seg[u].val=max(seg[ls(u)].val+seg[ls(u)].lz,seg[rs(u)].val+seg[rs(u)].lz);
}
void solvedp_2(){
    for(long long i=1;i<=1e6+1;i++) fle[i]=0;
    for(long long i=1;i<=n;i++){
        nnum[i]=nnum[i-1];
        if(!fle[a[i]]) nnum[i]++,fle[a[i]]=nnum[i],rfle[nnum[i]]=a[i];
        a[i]=fle[a[i]];
        // cout<<a[i]<<" ";
    }
    // cout<<"\n";
    build_seg(1,1,nnum[n]);
    long long ans=0;
    for(long long i=1;i<=n;i++){
        long long mx2=que(1,1,nnum[i]);
        long long mx=max(mx2,que(1,a[i],a[i])+rfle[a[i]]);
        if(a[i-1]==a[i]){
            add(1,1,nnum[i],rfle[a[i]]);
            // cout<<"X\n";
        }
        if(nnum[i]==nnum[i-1]){
            upd(1,a[i-1],mx);
            // cout<<mx<<"Y\n";
        }
        else upd(1,a[i-1],mx2);
        // for(long long j=1;j<=nnum[i];j++) cout<<que(1,j,j)<<" ";
        // cout<<"\n";
        // for(long long j=0;j<i-1;j++){
        //     f[i-1]=max(f[i-1],f[j]+(a[i]==a[j]?a[i]:0));
        // }
    }
    cout<<que(1,1,nnum[n])<<"\n";
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        scanf("%ld",&n);
        for(long long i=1;i<=n;i++) scanf("%ld",&a[i]);
        // solvedp();
        // cout<<"--\n";
        // solvedp_2();
        if(n<=2000) solvedp();
        else solvedp_2();
    }
	return 0;
}