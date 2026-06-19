#include <bits/stdc++.h>
using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
int n,m,k,ans,c,a[10005];
bool circle,vis[10005];
vector<pair<int,int> > mst_g[10005];
bool cmp(pair<pair<int,int>,int> x,
         pair<pair<int,int>,int> y){
    return x.second <= y.second;
}
vector<pair<pair<int,int>,int> > edge;
void prep(){
    fin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        int u,v,w;
        fin>>u>>v>>w;
        edge.push_back(make_pair(make_pair(u-1,v-1),w));

    }
    for(int i=0;i<k;++i){
        fin>>c;
        // cout<<"country: build cost is "<<c<<" and road cost is ";
        for(int j=0;j<n;++j){
            fin>>a[j];
            for(int u=0;u<j;++u){
                edge.push_back(make_pair(make_pair(u,j),a[u]+a[j]+c));
            }
            // cout<<a[j]<<" ";
        }
        // cout<<endl;
        /*for(int u=0;u<n;++u){
            for(int v=u+1;v<n;++v){
                edge.push_back(make_pair(make_pair(u,v),a[u]+a[v]+c));
                // cout<<"edge: "<<"connect "<<u+1<<" and "<<v+1<<" its weight is "<<a[u]<<" + "<<a[v]<<" + "<<c<<endl;
            }

        }*/
    }
}
void dfs(int prev,int index){
    if(vis[index]) {
        circle=true;
        return;
    }
    vis[index]=true;
    int len=mst_g[index].size();
    for(int i=0;i<len;++i){
        if(mst_g[index][i].first==prev)continue;
        dfs(index,mst_g[index][i].first);
    }
}
void kruscal(){
    while(!edge.empty()){
        circle=false;
        pair<pair<int,int>,int> tmp=edge[0];
        edge.erase(edge.begin());
        mst_g[tmp.first.first].push_back(make_pair(tmp.first.second,tmp.second));
        mst_g[tmp.first.second].push_back(make_pair(tmp.first.first,tmp.second));
        dfs(-1,tmp.first.first);
        memset(vis,0,sizeof(vis));
        if(circle){
            // cout<<"edge: "<<"connect "<<tmp.first.first+1<<" and "<<tmp.first.second+1<<" its weight is "<<tmp.second<<" has been add with circle\n";
            mst_g[tmp.first.first].pop_back();
            mst_g[tmp.first.second].pop_back();
            continue;
        }
        // cout<<"edge: "<<"connect "<<tmp.first.first+1<<" and "<<tmp.first.second+1<<" its weight is "<<tmp.second<<" has been add with no circle\n";
        ans+=tmp.second;
    }
}
int main(){
    prep();
    sort(edge.begin(),edge.end(),cmp);
    /*for(int i=0;i<edge.size();++i){
        cout<<"edge: "<<"connect "<<edge[i].first.first+1<<" and "<<edge[i].first.second+1<<" its weight is "<<edge[i].second<<endl;
    }*/
    kruscal();
    fout<<ans<<endl;
    return 0;
}