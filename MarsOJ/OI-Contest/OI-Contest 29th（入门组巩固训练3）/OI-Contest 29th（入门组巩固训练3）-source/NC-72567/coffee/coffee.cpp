#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","W",stdout);
    cin>>t;
    while(t--){
        int ans=0;
        for(int i=0;i<=40;i++){
            cin>>s;
            if(s=="math") ans++;
        }
        int n,m;
        cin>>n>>m;
        if(m==6){
            n--;
        }
        int da=(n/7)*5+n%7;
        ans*=da;
        cout<<ans<<endl;
    }
    return 0;
}
