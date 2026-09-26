#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int MAXN = 2005;

int n, a[MAXN], b[MAXN];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+n+1,greater<int>());
    sort(b+1,b+n+1,greater<int>());
    deque<int> t,q;
    for(int i=1;i<=n;i++) t.push_back(a[i]);
    for(int i=1;i<=n;i++) q.push_back(b[i]);

    int ans=0;
    while(!t.empty())
    {
        //田忌最强 >齐王最强
        if(t.front()>q.front())
        {
            ans+=200;
            t.pop_front(); q.pop_front();
        }
        //田忌最弱 >齐王最弱
        else if(t.back()>q.back())
        {
            ans+=200;
            t.pop_back(); q.pop_back();
        }
        //田忌最弱对上齐王最强
        else
        {
            if(t.back()<q.front()) ans-=200;
            t.pop_back(); q.pop_front();
        }
    }
    cout<<ans<<endl;
    return 0;
}