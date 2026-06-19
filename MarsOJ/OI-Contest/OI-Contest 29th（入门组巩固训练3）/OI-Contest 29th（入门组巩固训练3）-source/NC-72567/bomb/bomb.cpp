#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","W",stdout);
    cin>>t;
    while(t--){
        int ans=0;
        int n,m;
        cin>>n>>m;
        cin>>s;
        for(int i=0;i<m-1;i++){
            if(s[i]=='$') ans++;
        }
        cout<<ans<<' '<<m-1<<endl;
    }
    return 0;
}
