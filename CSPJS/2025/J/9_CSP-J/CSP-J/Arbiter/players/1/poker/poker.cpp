#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
    set<string> s;
    string a;
    int n;
    void Soar()
    {
        freopen("poker.in","r",stdin);
        freopen("poker.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            s.insert(a);
        }
        cout<<52-s.size()<<endl;
        return;
    }
}
int main()
{
    Soaring_Wings::Soar();
    return 0;
}