#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<vector<int>> e,ph,ok;
vector<int> s;
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        
    }
}int a;
int main()
{
    cin>>n>>m>>k;
    e.resize(n+1,vector<int>(0,0));
    s.resize(n+1);
    ph.resive(n+1,vector<int>(0,0));
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int b=2;b<=n;b++)
    {
        for(int c=2;c<=n;c++)
        {
            if(!ok[b][c])continue;
            for(int a:ph[b])
            {

            }
        }
    }
}