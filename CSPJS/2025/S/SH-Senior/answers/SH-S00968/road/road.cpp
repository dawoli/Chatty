#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int a,b,v;
};
bool check(node a,node b){
    return a.v<b.v;
}
int BIN(int a,int lbin[]){
    if (lbin[a]==a){
        return lbin[a];
    }
    else{
        lbin[a]=BIN(lbin[a],lbin);
        return lbin[a];
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    vector<node> l;
    for (int i=0;i<m;i++){
        node aa;
        cin>>aa.a>>aa.b>>aa.v;
        l.push_back(aa);
    }
    int cm=0;
    int lc[k+2];
    int lic[k+2][n+2];
    for (int i=1;i<=k;i++){
        cin>>lc[i];
        cm+=lc[i];
        for (int j=1;j<=n;j++){
            cin>>lic[i][j];
        }
    }
    if(k==0){
        sort(l.begin(),l.end(),check);
        int ans=0;
        int lbin[n+2];
        for (int i=1;i<=n;i++){
            lbin[i]=i;
        }
        for (int i=0;i<l.size();i++){
            cout<<"";
            lbin[l[i].a]=BIN(lbin[l[i].a],lbin);
            lbin[l[i].b]=BIN(lbin[l[i].b],lbin);
            if (lbin[l[i].a]!=lbin[l[i].b]){
                ans+=l[i].v;
                lbin[BIN(lbin[l[i].a],lbin)]=BIN(lbin[l[i].b],lbin);
            }
        }
        cout<<ans<<'\n';
	} 
    if (k!=0&&cm==0){
        for (int i=1;i<=k;i++){
            for (int j=1;j<=n;j++){
                l.push_back({i,j,lic[i][j]});
            }
        }
        sort(l.begin(),l.end(),check);
        int lbin[n+2];
        for (int i=1;i<=n;i++){
            lbin[i]=i;
        }
        int ans=0;
        for (int i=0;i<l.size();i++){
            cout<<"";
            lbin[l[i].a]=BIN(lbin[l[i].a],lbin);
            lbin[l[i].b]=BIN(lbin[l[i].b],lbin);
            if (lbin[l[i].a]!=lbin[l[i].b]){
                ans+=l[i].v;
                lbin[BIN(lbin[l[i].a],lbin)]=BIN(lbin[l[i].b],lbin);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
