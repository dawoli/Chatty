#include<bits/stdc++.h>
using namespace std;
const int N=110;
struct Node { int w; bool red; }a[N];
bool cmp(Node a,Node b) { return a.w>b.w; }
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i].w,a[i].red=(i==1);
    sort(a+1,a+n*m+1,cmp);
    int id=0;
    for(int i=1;i<=n*m;i++) if(a[i].red) { id=i; break; }
    int lie=(id-1)/n+1; cout<<lie<<' ';
    if(lie&1) cout<<(id-1)%n+1;
    else cout<<n-(id-1)%n;
    return 0;
}
