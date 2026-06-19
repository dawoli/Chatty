#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
bitset<MAXN> vis;
int n,m,q,l,x,r,c;
bool flag;
void dfs(int ct,int curIndex,int curPerson,vector<vector<int>> vc){
    if(vc[curPerson][curIndex]==c&&ct==r){
        flag=1;
        return;
    }
    if(ct==r)return;
    for(int i=1;i<=n;i++){
        if(i==curPerson)continue;
        for(int j=0;j<vc[i].size();j++){
            if(vc[i][j]==vc[curPerson][curIndex]){
                for(int ll=2;ll<vc[i].size()-j;ll++){
                    dfs(ct+1,j+ll,i,vc);
                }
            }
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&q);
        vector<vector<int>> vc(n+1);
        vector<pair<int,int>> starters;
        for(int i=1;i<=n;i++){
            scanf("%d",&l);
            for(int j=1;j<=l;j++){
                scanf("%d",&x);
                if(x==1)starters.push_back({i,j-1});
                vc[i].push_back(x);
                vis[x]=1;
            }
        }
        while(q--){
            scanf("%d%d",&r,&c);
            if(!vis[c]){
                puts("0");
                continue;
            }
            for(auto x:starters){
                dfs(0,x.second,x.first,vc);
            }
            cout<<flag<<endl;
        }
        flag=0;
        vis.reset();
    }
    return 0;
}