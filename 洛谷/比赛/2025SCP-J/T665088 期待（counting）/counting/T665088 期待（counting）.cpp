#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
    int T,n,y,s;
    void Soar()
    {
        vector<vector<int>> edge(n,vector<int>(0,0));
        vector<int> usize(n+1,0);
        for(int i=1;i<=n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            edge[x].push_back(y);
            edge[y].push_back(x);
            usize[x]=edge[x].size();
            usize[y]=edge[y].size();
        }
        if(count(usize.begin()+1,usize.end(),1)==n-1)
        {
            cout<<5<<endl;
            return;
        }
    }
    void solve()
    {
        cin>>T;
        while(T--)
        {
            cin>>n>>y>>s;
            Soar();
        }
    }
}
int main()
{
	Soaring_Wings::Soar();
	return 0;
}