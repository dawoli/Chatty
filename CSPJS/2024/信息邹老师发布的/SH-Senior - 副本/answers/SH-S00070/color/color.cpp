#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        map<int,int> mp;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            mp[x]++;
        }
        int ans=0;
        for(pair<int,int> p:mp){
            if(p.second>1)ans+=p.first;
        }
        printf("%d\n",ans);
    }
    return 0;
}