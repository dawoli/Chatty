#include<bits/stdc++.h>
using namespace std;
int t,ans;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    cin>>t;
    int n,m;
    while(t--){
        ans=0;
        for(int k=1;k<=40;k++){
            cin>>s;
            if(s=="math")
                ans++;
        }
        cin>>n>>m;
        if(m==6)
            n--;
        int day=(n/7)*5+n%7;
        ans*=day;
        cout<<ans<<'\n';
    }
    return 0;
}
