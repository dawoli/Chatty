#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool> vis;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int T;
    scanf("%d",&T);
    int ct=0;
    while(T--){
        string s;
        cin>>s;
        if(!vis[s])ct++,vis[s]=1;
    }
    printf("%d",52-ct);
    return 0;
}