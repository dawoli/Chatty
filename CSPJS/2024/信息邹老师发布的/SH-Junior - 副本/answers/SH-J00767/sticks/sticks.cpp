#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n==2){
            cout<<1;
            continue;
        }
        if(n==3){
            cout<<7;
            continue;
        }
        if(n==4){
            cout<<4;
            continue;
        }
        if(n==5){
            cout<<2;
            continue;
        }
        if(n==6){
            cout<<6;
            continue;
        }

        if(n%7==0){
            for(int j=1;j<=n/7;j++){
                cout<<8;
            }
            continue;
        }
        if(n<2){
            cout<<-1;
            continue;
        }
        if(n==8){
            cout<<10;
            continue;
        }
        if(n%7==1){
            cout<<10;
            n-=8;
            for(int j=1;j<=n/7;j++){
                cout<<8;
            }
            continue;
        }
        int tn=n%7+7;
        if(tn==9){
            cout<<18;
        }
        if(tn==10){
            cout<<22;
        }
        if(tn==11){
            cout<<20;
        }
        if(tn==12){
            cout<<28;
        }
        if(tn==13){
            cout<<80;
        }
        for(int j=0;j<=(n-tn)%7;j++){
            cout<<8;
        }
    }
    return 0;
}
