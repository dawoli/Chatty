#include<iostream>
#include<map>
#include<fstream>
using namespace std;
map<string,bool> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,ans=52;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(!mp[s])
            ans--;
        mp[s]=1;
    }
    cout<<ans;
    return 0;
}