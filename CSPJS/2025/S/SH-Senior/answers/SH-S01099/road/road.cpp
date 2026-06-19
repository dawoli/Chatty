#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
using ll =long long;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> u(m+1),v(m+1),w(m+1);
    if(k==0){

    }
    vector<int> c(k+1);
    vector<vector<int>> a(k+1);
    for(int i=1;i<=k;i++) a[i].resize(n+1);
    for(int i=1;i<=k;i++) {
        cin>>c[i];
        for(int j=1;j<=N;j++) cin>>a[i][j];
    }

    return 0;
}
