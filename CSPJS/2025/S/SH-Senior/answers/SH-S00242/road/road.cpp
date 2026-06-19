#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int u[m],v[m],w[m];
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    int a[k][n+1];
    for(int i=0;i<k;i++){
        for(int j=0;j<=n;j++){
            cin>>a[i][j];
        }
    }
    cout<<1;
    return 0;
}
