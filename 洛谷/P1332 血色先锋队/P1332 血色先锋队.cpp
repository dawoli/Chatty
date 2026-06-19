#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
    int n,m,a,b;
    vector<pair<int,int>> vir,ldr;
    queue<pair<int,int>> q;
    vector<int> ans;
    bitset<100001> vis;
    bool mark[501][501]={};
    int mx[5]={0,0,0,-1,1};
    int my[5]={0,1,-1,0,0};
    void bfs(int deep)
    {
        while(!q.empty())
        {
            auto qt=q.front();
            q.pop();
            mark[qt.first][qt.second]=1;
            for(int i=1;i<=b;i++)
            {
                if(!vis[i])
                {
                    if(qt==ldr[i])
                    {
                        ans[i]=deep;
                        vis[i]=1;
                    }
                }
            }
            int x=qt.first,y=qt.second;
            for(int i=1;i<=4;i++)
            {
                if(mark[x+mx[i]][y+my[i]]==0)
                {
                    q.push(make_pair(x+mx[i],y+my[i]));
                }
            }
            deep++;
        }
    }
    void Soar()
    {
        ios::sync_with_stdio(false);
        cin.tie(0),cout.tie(0);
        cin>>n>>m>>a>>b;
        vir.push_back(make_pair(0,0));
        ldr.push_back(make_pair(0,0));
        vis.reset();
        for(int i=1;i<=a;i++)
        {
            int x,y;
            cin>>x>>y;
            vir.push_back(make_pair(x,y));
            q.push(make_pair(x,y));
        }
        for(int i=1;i<=b;i++)
        {
            int x,y;
            cin>>x>>y;
            ldr.push_back(make_pair(x,y));
        }
        bfs(0);
        for(int i=1;i<=b;i++)
            cout<<ans[b]<<endl;        
    }
}
int main()
{
    Soaring_Wings::Soar();
    return 0;
}