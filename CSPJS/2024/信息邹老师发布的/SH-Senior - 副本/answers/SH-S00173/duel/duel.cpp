#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,c[N],ans,cntp,cnt[N],undefeated;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++)cin>>c[i];
    sort(c+1,c+n+1);
    for(int i=1;i<=n;i++){
        if(c[i]>c[i-1])cntp++;
        cnt[cntp]++;
    }
    // for(int i=1;i<=cntp;i++)cout<<cnt[i]<<" ";
    // cout<<endl;
    for(int i=2;i<=cntp;i++){
        if(cnt[i]<=cnt[i-1]){ans-=cnt[i];undefeated+=cnt[i-1]-cnt[i];}
        if(cnt[i]>cnt[i-1]){
            if(cnt[i]>=cnt[i-1]+undefeated){ans-=cnt[i-1]+undefeated;}
            else{undefeated-=cnt[i]-cnt[i-1];ans-=cnt[i];}
        }
    }
    cout<<ans<<endl;
    return 0;
}