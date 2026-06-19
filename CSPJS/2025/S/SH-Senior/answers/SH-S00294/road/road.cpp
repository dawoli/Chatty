#include <bits/stdc++.h>
#include <vector>
#define int long long
using namespace std;

const int N = 1e4 + 10;
struct Edge {
    int to, w;
};
vector<Edge> G[N];
vector<int> min_r(N, INT_MAX);

struct Node {
    int u,v,w;
};

bool cmp(Node a,Node b){
    return a.w>b.w;
}

signed main(){
    ignore = freopen("road.in","r",stdin);
    ignore = freopen("road.out","w",stdout);
    int n,m,k;
    int count = 0, ans=0;
    cin>>n>>m>>k;
    vector<Node> e;
    vector<int> cnt(n+1);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        min_r[u]=min(min_r[u], w);
        min_r[v]=min(min_r[v], w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
        e.push_back({u,v,w}); count ++;
        ans+=w;
        cnt[u]++;cnt[v]++;
    }
    for(int i=1;i<=k;i++){
        vector<int> a(n+1);
        int c;cin>>c;
        int t=INT_MAX;
        for(int j=1;j<=n;j++){
            cin>>a[j];
            t=min(t,c+a[j]);
        }
        t+=a[i];
        if(t>min_r[i]){
            // cout <<i<<"*"<<endl;
            continue;
        }
        else{
            ans+=c+a[i];
            cout<<"/"<<c+a[i]<<"/";
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                G[i].push_back({j,a[j]});
                G[j].push_back({i,a[j]});
                e.push_back({i,j,a[j]});count++;
                ans+=a[j];
                cnt[i]++;cnt[j]++;
            }
        }
    }
    sort(e.begin(),e.end(),cmp);
    // cout << ans<<endl;
    for(auto t:e){
        if(count<=n-1) break;
        if(cnt[t.u]>1 && cnt[t.v]>1){
            ans-=t.w;
            count--;
            cnt[t.u]--;
            cnt[t.v]--;
            // cout << "*";
        }
        // cout << t.u<<" "<<t.v<<" "<<t.w<<" "<<endl;
    }
    cout <<ans;
    return 0;
}
//g++ road.cpp -Wall -std=c++14 -O2 -o road
///home/cyez/D/SH-S00294sunheqi/road/road
/*
42
*1 2 8 
*2 3 7 
*1 4 6 
4 2 5 
*4 3 4 
*1 4 4 
1 3 2 
13

42
*1 2 8 
*2 3 7 
*1 4 6 
4 2 5 
*4 3 4 
17

*/