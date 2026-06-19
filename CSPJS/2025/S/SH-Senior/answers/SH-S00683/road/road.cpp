#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;
typedef long long ll;
const int N=1e4+15;
int fa[N],c[N];
int a[12][N];
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
void add(int x,int y){fa[find(y)]=find(x);}
vector<pair<int,pair<int,int>>>f,h;
int tmp[12],cnt=0;
void read(int&x){
    x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    read(n);
    read(m);
    read(k);
    for(int i=1;i<=n+k;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,w;
        read(u);
        read(v);
        read(w);
        f.push_back({w,{u,v}});
    }
    bool A=1;
    for(int i=1;i<=k;i++){
        read(c[i]);
        if(c[i])
            A=0;
        for(int j=1;j<=n;j++)
            read(a[i][j]);
    }
    if(A){
        for(int i=n+1;i<=n+k;i++)
            for(int j=1;j<=n;j++)
                f.push_back({a[i-n][j],{i,j}});
        m+=k*n;
        ll ans=0;
        sort(f.begin(),f.end());
        for(int i=0;i<m;i++){
            if(find(f[i].second.first)!=find(f[i].second.second)){
                ans+=f[i].first;
                add(f[i].second.first,f[i].second.second);
            }
        }
        printf("%lld\n",ans);
    }
    else{
        ll mx=1e18;
        for(int i=0;i<(1<<k);i++){
            for(int i=1;i<=n+k;i++)
                fa[i]=i;
            cnt=0;
            ll ans=0;
            h=f;
            for(int j=0;j<k;j++)
                if((i>>j)&1){
                    tmp[++cnt]=j+1;
                    ans+=c[j+1];
                    for(int l=1;l<=n;l++)
                        h.push_back({a[j+1][l],{j+1,l}});
                }
            sort(h.begin(),h.end());
            for(int i=0;i<m+n*cnt;i++){
                if(find(h[i].second.first)!=find(h[i].second.second)){
                    ans+=h[i].first;
                    add(h[i].second.first,h[i].second.second);
                }
            }
            mx=min(mx,ans);
        }
        printf("%lld\n",mx);
    }
    return 0;
}