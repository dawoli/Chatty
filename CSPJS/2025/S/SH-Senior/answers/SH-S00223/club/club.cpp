#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int t;
int n;
int a[MAXN][5];
int h1,h2,h3;
int h[MAXN][5];
int cha[MAXN];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        h1=1,h2=1,h3=1;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1];
            cin>>a[i][2];
            cin>>a[i][3];
            int ma=max(a[i][1],max(a[i][2],a[i][3]));
            ans+=ma;
            if(ma==a[i][1]){
               h[h1++][1]=i;
            }else if(ma==a[i][2]){
               h[h2++][2]=i;
            }else if(ma==a[i][3]){
                h[h3++][3]=i;
            }
        }
        if(h1>(n/2)){
            for(int i=1;i<h1;i++){
                cha[i]=min(a[h[i][1]][1]-a[h[i][1]][2],a[h[i][1]][1]-a[h[i][1]][3]);
            }
            sort(cha+1,cha+h1,cmp);
            for(int i=h1-1;i>(n/2);i--){
                ans-=cha[i];
            }
        }
         else if(h2>(n/2)){
            for(int i=1;i<h2;i++){
                cha[i]=min(a[h[i][2]][2]-a[h[i][2]][1],a[h[i][2]][2]-a[h[i][2]][3]);
            }
            sort(cha+1,cha+h2,cmp);
            for(int i=h2-1;i>(n/2);i--){
                ans-=cha[i];
            }
        }
         else if(h3>(n/2)){
            for(int i=1;i<h3;i++){
                cha[i]=min(a[h[i][3]][3]-a[h[i][3]][1],a[h[i][3]][3]-a[h[i][3]][2]);
            }
            sort(cha+1,cha+h3,cmp);
            for(int i=h3-1;i>(n/2);i--){
                ans-=cha[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
