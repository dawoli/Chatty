#include<bits/stdc++.h>
using namespace std;
int n,m,q;
vector<vector<int>> e;//存的是入边，不要搞反了
vector<int> uab;
int main()
{
    cin>>n>>m;
    e.resize(n+1,vector<int>(0,0));
    uab.resize(n+1,0);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        e[y].push_back(x);
        uab[y]++;
    }
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int t,u,v;
        cin>>t;
        switch(t)
        {
        case 1:
            cin>>u>>v;
            uab[v]--;
            break;
        case 2:
            cin>>u;
            uab[v]=0;
            break;
        case 3:
            cin>>u>>v;
            uab[v]++;
            break;
        case 4:
            cin>>u;
            uab[u]=e[u].size();
            break;
        }
        if(accumulate(uab.begin()+1,uab.end(),0)==n)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        /*
        for(auto it:uab)
        {
            cout<<it<<' ';
            cout<<endl;
        }
        */
    }
    return 0;
}