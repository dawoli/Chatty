#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
    x=0;bool neg=0;char ch;
    for(ch=getchar();ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
    if(ch=='-'){
        neg=1;ch=getchar();
    }
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
    if(neg)x=-x;
}
int n,m,L,V;
struct CAR{
    int d,v,a,l,r;
    void solve(){
        if(a==0){
            l=d;
            if(v>V)r=L;
            else if(v<=V)r=d-1;
        }else if(a>0){
            r=L;
            if(v>V)l=d;
            else if(v<=V)
                l=min(L+1,d+1+(V*V-v*v)/(a<<1));
        }else if(a<0){
            l=d;
            if(v<=V)r=d-1;
            else if(v>V)
                r=min(L,d+(v*v-V*V-1)/((-a)<<1));
        }
    }
}C[100005];
int p[100005];
struct LR{
    int l,r,id;
}nec[100005],hp[100005];
int comp1(const LR &a,const LR &b){
    return a.l<b.l;
}
int comp2(const LR &a,const LR &b){
    return a.r<b.r;
}
bool B[100005];
int top;
int ans;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int i,j,T;
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        for(i=1;i<=n;i++){
            read(C[i].d);
            read(C[i].v);
            read(C[i].a);
            C[i].solve();
        }
        for(i=1;i<=m;i++)
            read(p[i]);
        p[m+1]=L+1;
        ans=0;top=0;
        for(i=1;i<=n;i++){
            if(*lower_bound(p+1,p+m+1,C[i].l)<=C[i].r){
                ans++;
                nec[++top].l=lower_bound(p+1,p+m+1,C[i].l)-p;
                nec[top].r=upper_bound(p+1,p+m+1,C[i].r)-p-1;
                nec[top].id=top;
                hp[top]=nec[top];
            }
        }
        printf("%d ",ans);
        sort(nec+1,nec+top+1,comp1);
        sort(hp+1,hp+top+1,comp2);
        memset(B,0,top+2);
        ans=0;
        for(i=1,j=1;i<=top;i++){
            while(B[hp[i].id])i++;
            if(i>top)break;
            ans++;
            while(j<=top&&nec[j].l<=hp[i].r){
                B[nec[j].id]=1;
                j++;
            }
            if(j>top)break;
        }
        printf("%d\n",m-ans);
    }
    return 0;
}