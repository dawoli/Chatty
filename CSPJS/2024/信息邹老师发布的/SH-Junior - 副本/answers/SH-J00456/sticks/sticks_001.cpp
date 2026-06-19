#include "bits/stdc++.h"
using namespace std;
#define int long long
int a[1000003];
int work(int r){
    if(r == 6){
        return 6;
    }
    else if(r == 2) return 1;
    else if(r == 5) return 2;
    else if(r == 4) return 4;
    else if(r == 3) return 7;
    else if(r == 7) return 8;
    else return -1;
}
int work2(int r){
    if(r == 1){
        return 2;
    }
    else if(r ==0 ) return 6;//重要
    else if(r == 2) return 5;
    else if(r == 3) return 5;
    else if(r == 4) return 4;
    else if(r == 5) return 5;
    else if(r == 6) return 6;
    else if(r == 7) return 3;
    else if(r == 8) return 7;
    else if(r == 9) return 6;
    else return -1;
}
int shzi(int u){
    int x =0,r = 0;
    while (u!=0){
        r =  u%10;
        x+=work2(r);
        u = u/10;
    }
    return x;

}
namespace T{
    typedef long long ll;
    vector <ll> v;

    void fun(ll n){
        for(ll i = 10;i<=100050;i++){
            if(shzi(i) == n){
                v.push_back(i);
            }
        }

    }


};




signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;cin>>T;
    for(int i = 1;i<=T;i++){
        cin>>a[i];
    }
    for(int i =1;i<=T;i++){
        int k = a[i];
        if(k<=9){
            int ans = work(k);
            if(ans == -1){
                cout<<-1<<"\n";
            }
            else cout<<ans<<"\n";
        }
        else{
            T::fun(k);
            sort(T::v.begin(),T::v.end());
            cout<<T::v[0]<<"\n";

        }

    }




    return 0;
}




