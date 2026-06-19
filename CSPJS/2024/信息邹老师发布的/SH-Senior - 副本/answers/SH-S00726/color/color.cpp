#include<bits/stdc++.h>
using namespace std; const int N=200010,L=1000010; using ll=long long; int v[N]; ll h[N],l[L];
int w(int x,int y){ return v[x]==v[y]?v[x]:0; }
int main(){
    freopen("color.in","r",stdin); freopen("color.out","w",stdout);
    int T; scanf("%d",&T);
    while(T--){
        int n; scanf("%d",&n); ll s=0,M=0;
        for(int i=1;i<=n;++i) scanf("%d",&v[i]),l[v[i]]=-1e18,s+=w(i-1,i); 
        for(int i=1;i<n;++i){
            h[i]=max(M,v[i+1]+l[v[i+1]])-w(i,i+1);
            l[v[i]]=max(l[v[i]],h[i]); M=max(M,h[i]);
        }
        //for(int i=0;i<n;++i) cout<<i<<" "<<h[i]<<endl;
        printf("%lld\n",M+s);
    }
    return 0;
}