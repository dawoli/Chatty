#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<long long,long long> pll;
typedef long long ll;
ll solve(const ll &sx, const ll &sy)
{
    pll nx={-1,0},ny={0,1};
    vector<ll> fib(0);
    fib.push_back(1);
    for (ll i=1;;i++)
    {
        if (nx.x<=sx&&nx.y<=sy&&sx<=ny.x&&sy<=ny.y)
        {
            return *(fib.end()-1);
        }
        if (i==2)
        {
            nx={-1,-1};
            ny={0,0};
            fib.push_back(1);
            continue;
        }
        if (i==1)continue;
        fib.push_back(fib[fib.size()-1]+fib[fib.size()-2]);
        const ll op=(i-2)%4;
        const ll e=*(fib.end()-1);
        const ll e2=*(fib.end()-2);
        switch (op)
        {
        case 1:
            nx={nx.x+e2,nx.y};
            ny={nx.x+e,nx.y+e};
            break;
        case 2:
            nx={ny.x-e,ny.y};
            ny={nx.x+e,nx.y+e};
            break;
        case 3:
            ny={ny.x-e2,ny.y};
            nx={ny.x-e,ny.y-e};
            break;
        case 0:
            nx={nx.x,nx.y-e};
            ny={nx.x+e,nx.y+e};
            break;
        }
    }
}
int main()
{
    ll T;
    cin>>T;
    while (T--)
    {
        ll ix,iy;
        cin>>ix>>iy;
        cout<<solve(ix,iy)<<endl;
    }
    return 0;
}