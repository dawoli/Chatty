#include<bits/stdc++.h>
using namespace std;
inline int read(){
    char c=getchar_unlocked();
    int f=0;
    while(!isdigit(c))c=getchar_unlocked();
    while(isdigit(c))f=f*10+c-'0',c=getchar_unlocked();
    return f;
}
struct worker{
    int x,y,fch;
    bool operator>(const worker &w)const{
        return x>w.x;
    }
}as[100005];
int a[100005][5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t=read();
    while(t--){
        int n=read();
        long long ans=0;
        vector<int>delta[4];
        for(int i=1;i<=n;i++){
            a[i][1]=read();
            a[i][2]=read();
            a[i][3]=read();
            int maxa=max({a[i][1],a[i][2],a[i][3]});
            if(a[i][1]==maxa)as[i].x=a[i][1],as[i].fch=1,as[i].y=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
            else if(a[i][2]==maxa)as[i].x=a[i][2],as[i].fch=2,as[i].y=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
            else if(a[i][3]==maxa)as[i].x=a[i][3],as[i].fch=3,as[i].y=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
            ans+=maxa;
            delta[as[i].fch].push_back(as[i].y);
        }
        for(int i=1;i<=3;i++)
            if(delta[i].size()>n/2){
                sort(delta[i].begin(),delta[i].end());
                int limit=delta[i].size()-n/2;
                for(int j=0;j<limit;j++)ans-=delta[i][j];
            }
        printf("%lld\n",ans);
    }
    return 0;
}
//g++ -O2 -std=c++14 -static club.cpp -Wall -o club
//g++ -O2 -std=c++14 -static club.cpp -Wall -o club && ./club
/*
10
(2020) 14533 [18961]
(2423) 15344 [16322]
(1910) 6224 [16178]
(2038) 9963 [19722]
8375 [10557] (5444)
(3518) 14615 [17976]
(6188) 13424 [16615]
[8769] (509) 4394
(958) 3195 [9953]
[16441] (5313) 10926

*/