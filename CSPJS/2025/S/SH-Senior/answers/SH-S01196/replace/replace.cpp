#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef __int128_t INT;
bool STST;
const int N=4e5+9,M=1e7+9,B=13331;
const LL P=1000000007LL*1000000009LL;
int n,m,Q;
char s0[M],s1[M];
char str[M]; int tot;
PII ps[N][2],pt[N][2];
int whs[N][2],wht[N][2];
struct node{
    LL h0,h1; int i;
    bool operator<(const node &W)const{
        if(h0^W.h0) return h0<W.h0;
        if(h1^W.h1) return h1<W.h1;
        return i<W.i;
    }
}nd[N];
int h[M],ne[N],idxe=1; PII e[N];
void add(int a,PII b){
    // printf("add %d %d %d\n",a,b.fi,b.se);
    e[idxe]=b,ne[idxe]=h[a],h[a]=idxe++;
}
int tr[M][26],idx;
int dfn[M],R[M],timestamp;
void cl(int u){
    memset(tr[u],0,sizeof(tr[u]));
    h[u]=0;
}
struct Trie{
    int rt;
    void clear(){
        cl(rt=++idx);
    }
    int ins(PII P){
        int p=rt;
        // printf("P %d %d\n",P.fi,P.se);
        for(int i=P.fi;i<=P.se;i++){
            int u=str[i]-'a';
            if(!tr[p][u]) cl(tr[p][u]=++idx)/* ,printf("tr %d %d %d\n",p,u,idx) */;
            p=tr[p][u];
        }
        // printf("p = %d\n",p);
        return p;
    }
    void dfs(int u){
        dfn[u]=++timestamp;
        for(int i=0;i<26;i++) if(tr[u][i]) dfs(tr[u][i]);
        R[u]=timestamp;
    }
    void build(){
        timestamp=0;
        dfs(rt);
    }
}T0,T1;
int bit[M];
void mdf(int x,int c){
    // printf("mdf %d %d\n",x,c);
    for(;x<=timestamp;x+=x&-x) bit[x]+=c;
}
int qry(int x){
    // printf("qry %d\n",x);
    int res=0;
    for(;x;x&=x-1) res+=bit[x];
    return res;
}
int res[N];
void dfs(int u){
    for(int i=h[u];i;i=ne[i]){
        if(e[i].se>0) mdf(e[i].fi,1),mdf(e[i].se+1,-1);
        else res[-e[i].se]+=qry(e[i].fi);
    }
    for(int i=0;i<26;i++) if(tr[u][i]) dfs(tr[u][i]);
    for(int i=h[u];i;i=ne[i]){
        if(e[i].se>0) mdf(e[i].fi,-1),mdf(e[i].se+1,1);
    }
}
bool EDED;
int main(){
    // cerr<<(&EDED-&STST)/1048576.0<<"\n";
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // cin>>n>>Q;
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++){
        scanf("%s%s",s0,s1);
        // cin>>s0>>s1;
        int len=strlen(s0),l=len,r=0;
        for(int j=0;j<len;j++) if(s0[j]!=s1[j]) l=min(l,j),r=max(r,j);
        if(l>r) continue;
        // printf("s %d %d %d\n",i,l,r);
        LL h0=0,h1=0;
        for(int j=l;j<=r;j++) h0=((INT)h0*B+s0[j])%P,h1=((INT)h1*B+s1[j])%P;
        ps[i][0].fi=tot+1;
        for(int j=l-1;~j;j--) str[++tot]=s0[j];
        ps[i][0].se=tot;
        ps[i][1].fi=tot+1;
        for(int j=r+1;j<len;j++) str[++tot]=s0[j];
        ps[i][1].se=tot;
        // printf("s0 %d: ",i); for(int j=ps[i][0].fi;j<=ps[i][0].se;j++) putchar(str[j]); puts("");
        // printf("s1 %d: ",i); for(int j=ps[i][1].fi;j<=ps[i][1].se;j++) putchar(str[j]); puts("");
        nd[++m]={h0,h1,-i};
    }
    for(int i=1;i<=Q;i++){
        scanf("%s%s",s0,s1);
        // cin>>s0>>s1;
        int len=strlen(s0),l=len,r=0;
        if(strlen(s1)!=len) continue;
        for(int j=0;j<len;j++) if(s0[j]!=s1[j]) l=min(l,j),r=max(r,j);
        if(l>r) continue;
        // printf("t %d %d %d\n",i,l,r);
        LL h0=0,h1=0;
        for(int j=l;j<=r;j++) h0=((INT)h0*B+s0[j])%P,h1=((INT)h1*B+s1[j])%P;
        pt[i][0].fi=tot+1;
        for(int j=l-1;~j;j--) str[++tot]=s0[j];
        pt[i][0].se=tot;
        pt[i][1].fi=tot+1;
        for(int j=r+1;j<len;j++) str[++tot]=s0[j];
        pt[i][1].se=tot;
        // printf("t0 %d: ",i); for(int j=pt[i][0].fi;j<=pt[i][0].se;j++) putchar(str[j]); puts("");
        // printf("t1 %d: ",i); for(int j=pt[i][1].fi;j<=pt[i][1].se;j++) putchar(str[j]); puts("");
        nd[++m]={h0,h1,i};
    }
    // printf("str: "); for(int j=1;j<=tot;j++) putchar(str[j]); puts("");
    sort(nd+1,nd+1+m);
    for(int i=1,j=0;i<=m;i=j+1){
        idx=0; idxe=1;
        T0.clear(),T1.clear();
        // puts("nwrd");
        while(j+1<=m&&nd[j+1].h0==nd[i].h0&&nd[j+1].h1==nd[i].h1){
            j++;
            int u=nd[j].i;
            if(u<0){
                u=-u;
                // printf("S %d\n",u);
                whs[u][0]=T0.ins(ps[u][0]);
                whs[u][1]=T1.ins(ps[u][1]);
            }
            else{
                // printf("T %d\n",u);
                wht[u][0]=T0.ins(pt[u][0]);
                wht[u][1]=T1.ins(pt[u][1]);
            }
        }
        T0.build();
        // printf("timestamp %d\n",timestamp);
        for(int k=j,u;k>=i;k--){
            u=nd[k].i;
            if(u<0){
                u=-u;
                add(whs[u][1],(PII){dfn[whs[u][0]],R[whs[u][0]]});
            }
            else{
                add(wht[u][1],(PII){dfn[wht[u][0]],-u});
            }
        }
        dfs(T1.rt);
    }
    for(int i=1;i<=Q;i++) printf("%d\n",res[i]);
    return 0;
}