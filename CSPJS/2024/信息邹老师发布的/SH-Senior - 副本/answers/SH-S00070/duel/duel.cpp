#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
map<int,int> mp;
int n;
bool vis[MAXN];
bool chk(){
    int ct=0;
    for(pair<int,int> p:mp){
        if(p.second<0)return 0;
        if(p.second)ct++;
        if(ct>1)return 1;
    }
    return 0;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    // int min_element=INT_MAX;
    priority_queue<int> r;
    // vector<int> r;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(!vis[x]){
            r.push(x);
            vis[x]=1;
        }
        mp[x]++;
        // min_element=min(min_element,x);
    }
    // int maxmn=mn.top();mn.pop();
    // int nxmn=mn.top();
    int mxx=r.top();
    int ct=0;
    while(chk()){
        int mx=r.top();r.pop();
        int minus=mp[mx];
        bool flag=0;
        for(pair<int,int> p:mp){
            if(p.first<=mx&&p.second>0){
                mp[p.first]-=minus;
                flag=1;
            }
        }
        if(flag) ct+=minus;
    }
    if(mxx==2)printf("%d",ct);
    else{
        int ans=0;
        for(pair<int,int> p:mp){
            if(p.second){
                ans=max(ans,abs(p.second));
            }
        }
        printf("%d",ct+ans);
    }
    // sort(r+1,r+n+1,greater<int>());
    // int ct=0;
    // while(!chk()){
    //     int x,id;
    //     for(int i=1;i<=n;i++){
    //         if(!vis[i]){
    //             x=r[i];
    //             id=i;
    //             break;
    //         }
    //     }
    //     if(x==min_element)break;
    //     vis[id]=1;
    //     // bool flag=0;
    //     while(id<=n){
    //         while(r[id]==x&&id<=n)id++;
    //         // if(id>n){
    //         //     flag=1;
    //         //     break;
    //         // }
    //         x=r[id];
    //         vis[id]=1;
    //     }
    //     ct++;
    // }
    // printf("%d",ct);
    return 0;
}