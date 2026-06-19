#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;

int cnt[4][maxn];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin>>T;
    int n;
    ll ans=0;
    while(T--) {
        ans=0;
        cin>>n;
        cnt[1][0]=0; cnt[2][0]=0; cnt[3][0]=0;
        int p1, p2, p3;
        int mx, sc, mi;
        for(int i=1;i<=n;i++) {
            cin>>p1>>p2>>p3;
            mx=p1, sc=p2, mi=1;
            if(p2>p1) {
                mx=p2, sc=p1, mi=2;
            }
            if(p3>mx) {
                sc=mx; mx=p3; mi=3;
            } else if(p3>sc) {
                sc=p3;
            }
            cnt[mi][++cnt[mi][0]]=mx-sc;
            ans+=mx;
        }
        pair<int,int> x=max(make_pair(cnt[3][0], 3), max(make_pair(cnt[1][0], 1), make_pair(cnt[2][0], 2)));
        int m=x.second;
        if(cnt[m][0]<=n/2) {
            cout<<ans<<'\n';
            continue;
        }
        sort(cnt[m]+1, cnt[m]+cnt[m][0]+1);
        for(int i=1;i<=cnt[m][0]-n/2;i++) {
            ans-=cnt[m][i];
        }
        cout<<ans<<'\n';
    }

    return 0;
}