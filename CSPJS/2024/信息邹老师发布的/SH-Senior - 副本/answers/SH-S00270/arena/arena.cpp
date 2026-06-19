#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,c,k,kl,q[N],lg[N];
bool v[N],d[N<<2],vx[N<<2];
int xw[4],a[N],al[N],w[N<<2],tl;
long long an[N],ans,ansl;

void solve(){
    for(int i=1;i<=(1<<k);i++)v[i]=0;
    for(int i=1;i<=(1<<(k+1));i++)w[i]=-1,vx[i]=0;
    int x;bool ok;ans=1;kl=0;
    for(int i=0;i<4;i++)cin>>xw[i];
    for(int i=1;i<=n;i++)a[i]=al[i]^xw[i%4];//cout<<'\n';
    for(int i=1;i<=n;i++){
        x=i+(1<<k)-1;ok=1;w[x]=a[i];
        for(int j=0;j<=kl-1;j++){
            if(!(d[x>>(j+1)]^((x>>j)&1))){//cout<<x<<" "<<j<<"\n";
                if(a[i]<j+1)ok=0;
                if(w[x>>j]>=0){
                    if(w[x>>j]>j)w[x>>(j+1)]=w[x>>j];
                    else w[x>>(j+1)]=w[(x>>j)^1];
                }
                if(w[x>>j]>j&&(!vx[(x>>j)^1])){//cout<<"shan: "<<x<<" "<<j<<"\n";
                    tl=(x>>j)^1;
                    for(int u=(tl<<j)-(1<<k)+1;u<((tl+1)<<j)-(1<<k)+1;u++){
                        ans-=u*(!v[u]),v[u]=1;
                    }//cout<<'\n';
                    vx[(x>>j)^1]=1;
                }
            }else{
                if(w[(x>>j)^1]>j)ok=0;
                if(w[(x>>j)^1]>=0){
                    if(w[(x>>j)^1]>j)w[x>>(j+1)]=w[(x>>j)^1];
                    else w[x>>(j+1)]=w[x>>j];
                }
            }
        }if((!ok)&&(!v[i]))ans-=i,v[i]=1;an[i]=ans;//cout<<i<<" "<<an[i]<<"\n";
        // for(int i=1;i<(1<<(k+1));i++)cout<<w[i]<<" ";cout<<"\n";
        if((1<<lg[i])==i){
            kl++;for(int j=i+1;j<=(1<<kl);j++)ans+=j;
            if(d[1<<(k-kl)]==0&&w[1<<(k-kl+1)]<kl&&(!vx[1<<(k-kl+1)])){
                for(int u=1;u<=i;u++)ans-=u*(!v[u]),v[u]=1;
                vx[1<<(k-kl+1)]=1;
            }
        }//cout<<"v[6]: "<<v[6]<<"\n";
    }ansl=0;
    for(int i=1;i<=m;i++)ansl^=an[q[i]]*i;
    cout<<ansl<<"\n";
}

int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;k=0;while((1<<k)<n)k++;
    for(int i=1;i<=n;i++)cin>>al[i];
    for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
    for(int i=1;i<=m;i++)cin>>q[i];
    for(int i=k;i>=1;i--){char c;
        for(int j=1;j<=(1<<(i-1));j++)
            cin>>c,d[(1<<(i-1))+j-1]=(c=='1');
    }cin>>c;
    // for(int i=1;i<(1<<k);i++)cout<<d[i]<<" ";cout<<'\n';
    for(int i=1;i<=c;i++)solve();
    return 0;
}