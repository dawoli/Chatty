#include<bits/stdc++.h>
using namespace std; const int N=131100; using ll=long long; using vc=vector<int>; using pi=pair<vc,vc>;
int A[N],a[N],q[N],x[5],f[N]; char s[20][N]; ll r[N]; vc V;
/*
pi sol(int h,int o){
    vc W,A; int m=(1<<h),n=m/2; A.resize(m+1);
    if(h==0){ W.push_back(1); A[0]=0,A[1]=o+1; return v; }
    pi L=sol(h-1,o),R=solr(h-1,o+n); vc &l=L.first,&r=R.first,&la=L.second,&a=R.second;
    for(int i=0;i<=n;++i) A[i]=la[i];
    //if(s[h][o/m]=='0'){
        ll s=0; for(int x:l) if(a[x]>=h) W.push_back(x),s+=x;
        if(W.empty()){
            A=a;
            for(int i=n+1;i<=m;++i) A[i]=a[i];
        }
        else{ for(int i=n+1;i<=m;++i) A[i]=s; }
    }
    else{
        ll s=0; for(int x:l) if(a[x]>=h) W.push_back(x),s+=x;
        if(W.empty()){
            A=a;
            for(int i=n+1;i<=m;++i) A[i]=a[i];
        }
        else{ for(int i=n+1;i<=m;++i) A[i]=s; }
    }
}
*/
vc win(int h,int o){
    vc v; int m=(1<<h),n=m/2;
    if(h==0){ v.push_back(o+1); return v; }
    vc l=win(h-1,o),r=win(h-1,o+n);
    if(s[h][o/m]=='1') swap(l,r);
    for(int x:l) if(a[x]>=h) v.push_back(x);
    //if(h==2) cout<<s[h][o/m]<<" "<<v.size()<<endl;
    if(v.size()<l.size()) for(int x:r) v.push_back(x);
    //if(h==2) cout<<v.size()<<endl;
    for(int x:l) if(a[x]<0) v.push_back(x);
    //cout<<h<<"lv "<<o<<" "<<v[0]<<" "<<a[v[0]]<<" "<<s[h][o/m]<<" "<<o/m<<endl;
    return v;
}
int main(){
    freopen("arena.in","r",stdin); freopen("arena.out","w",stdout);
    int N,m,h=0,n,F=1; scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&A[i]);
    for(int i=1;i<=m;++i) scanf("%d",&q[i]),f[q[i]]=1;
    while((1<<h)<n) ++h; N=(1<<h);
    for(int i=1;i<=h;++i) scanf("%s",s[i]);
    for(int i=1;i<=h;++i) for(int l=strlen(s[i]),j=0;j<l;++j) F&=(s[i][j]==0);
    //cout<<q[m]<<" "<<strlen(s[1])<<" "<<s[1][96]<<endl;
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&x[0],&x[1],&x[2],&x[3]); ll g=0;
        for(int i=1;i<=N;++i) a[i]=i<=n?A[i]^x[i%4]:-1;
        for(int i=n,j=h;i>0;a[i]=-1,--i){
            if(i<=(1<<(j-1))) --j;
            if(!f[i]) continue;
            V=win(j,0); r[i]=0;
            for(int x:V) r[i]+=x;
            //for(int x:V) cout<<x<<" "; cout<<r[i]<<" "<<i<<" "<<j<<"----------------"<<endl;
        }
        for(int i=1;i<=m;++i) g^=(i*r[q[i]]);
        printf("%lld\n",g);
    }
    return 0;
}