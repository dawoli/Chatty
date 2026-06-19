#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void f(){
    ll cnt[10],tot=0;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=5;i++){
        for(int j=1;j<=8;j++){
            string x;
            cin >> x;
            if(x=="math")   cnt[i]++;
        }
    }
    ll n,m,els=0;
    cin >> n >> m;
    for(int i=m;i<=7;i++){
        els++;
        tot+=cnt[i];
    }
    ll s=(m+(n%7)-1)%7;
    for(int i=1;i<=s;i++){
        els++;
        tot+=cnt[i];
    }
    tot+=(n-els)/7*(cnt[1]+cnt[2]+cnt[3]+cnt[4]+cnt[5]);
    cout << tot << endl;
}
int t;
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    cin >> t;
    while(t--)  f();
    return 0;
}
