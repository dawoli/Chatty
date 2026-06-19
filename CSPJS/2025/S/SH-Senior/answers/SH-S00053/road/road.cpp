#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX1=1e4+5;
const int MAX2=1e6+5;
const int MAX3=1e9+5;
int n,m,k,u[MAX2],v[MAX2],w[MAX2],c[12],a[11][MAX2];
// struct road{
//     int pr;
// } w[MAX1],a[12][MAX2];
int main()
{
    cin.tie(nullptr);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    return 0;
}