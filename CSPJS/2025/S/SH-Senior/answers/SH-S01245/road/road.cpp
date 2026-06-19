#include <bits/stdc++.h>

using namespace std;

const int N=10010;
const int M=1000010;
int n,m,k;
struct road
{
    int a;
    int b;
    int mon;
}rs[M];
int v[10];
int mb[10][N];
int head[N+10];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>rs[i].a>>rs[i].b>>rs[i].mon;
    }
    for(int i=0;i<k;i++){
        cin>>v[i];
        for(int j=0;j<n;j++){
            cin>>mb[i][j];
        }
    }
    for(int i=0;i<n+k;i++){
        head[i]=i;
    }
    return 0;
}

