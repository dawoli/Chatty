#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=0x3f3f3f3f;
long long a[1000005];
struct node{
    int w,t;
}b[10005];
bool cmp(node a,node b){
    return a.t<b.t||(a.t==b.t&&a.w<b.w);
}
void dfs(int id,int sum,int sumw){
    if(sum>=ans||sum<=0) return;
    if(id>n){ans=sum;return;}
    if(sumw+b[id].w<=m) dfs(id+1,sum+(sumw+b[id].w)*(b[id+1].t-b[id].t),sumw+b[id].w);
    dfs(id+1,sum+a[sumw+b[id].w],0);
}
int main(){
    freopen("package.in","r",stdin);
    freopen("package.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i].t>>b[i].w;
    sort(b+1,b+n+1,cmp);
    dfs(1,0,0);
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
