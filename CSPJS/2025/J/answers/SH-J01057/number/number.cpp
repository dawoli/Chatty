#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+9;
ll cnt[19];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    ll n=s.size(),flag=0;
    for(ll i = 0;i < n;i++){
        if(s[i]>='0' && s[i]<='9')cnt[s[i]-'0']++;
    }
    for(ll i = 9;i >= 1;i--){
        while(cnt[i]){
            flag=1;
            cout<<i;
            cnt[i]--;
        }
    }
    if(flag){
        while(cnt[0])cout<<0,cnt[0]--;
    }
    else cout<<0;
    return 0;
}
