#include <bits/stdc++.h>
using namespace std;
int n;
int ans=0x3f3f3f3f;
int num[10]={6,2,5,5,4,5,6,3,7,6};
void dfs(int last,int now){
    if(last==0){
        if(now<=ans)ans=now;
        return;
    }
    for(int i=0;i<10;i++){
        if(now==0 && i==0)continue;
        if(last-num[i]>=0)dfs(last-num[i],now*10+i);
    }
}
int main(){
	freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        if(n==1){cout<<-1<<endl;continue;}
        dfs(n,0);
        cout<<ans<<endl;
        ans=0x3f3f3f3f;
    }
    return 0;
}
