#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,y;
int a,now,b;
int xx,yy;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>x>>y>>a;
    int sum=x*y;
    b=0;
    for(int i=2;i<=sum;i++){
        cin>>now;
        if(now>=a)
            b++;
    }
    b++;
    xx=0;
    yy=0;
    xx+=b/(2*x)*2;
    b-=xx*x;
    if(b==0)cout<<xx<<" "<<0;
    else if(b<=x){
        xx++;
        yy=b;
        cout<<xx<<" "<<yy;
    }else{
        xx+=2;
        yy=2*x-b+1;
        cout<<xx<<" "<<yy;
    }
    return 0;
}
