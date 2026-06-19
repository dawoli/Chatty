#include<bits/stdc++.h>
using namespace std;
// 花色:DCHS
map<string,bool> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        if(mp[t]){
            n--;i--;
        }else{
            mp[t]=true;
        }
    }
    cout<<52-n;
    fclose(stdin);
    fclose(stdout);return 0;
}