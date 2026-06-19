#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f

const int maxn=1e5+5;

int as[maxn], c[maxn];
int a[maxn];
int x[4];

int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>as[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    int T;
    cin>>T;
    while(T--) {
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++) a[i]=as[i]^x[i&3];


        
    }
    return 0;
}