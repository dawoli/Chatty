#include <bits/stdc++.h>
using namespace std;
int t,n,m,a[100010][4],m1[100010],m2[100010],b[100010],p[100010],ans,cnt[4];
bool cmp(int x,int y) {
    return b[x]>b[y];
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for (int _=1;_<=t;++_) {
        cin>>n;
        m=n>>1;
        for (int i=1;i<=n;++i) {
            m1[i]=0;
            m2[i]=0;
            for (int j=1;j<=3;++j) {
                cin>>a[i][j];
                if (a[i][j]>a[i][m1[i]]) m2[i]=m1[i],m1[i]=j;
                else if (a[i][j]>a[i][m2[i]]) m2[i]=j;
            }
            b[i]=a[i][m1[i]]-a[i][m2[i]];
            p[i]=i;
        }
        sort(p+1,p+n+1,cmp);
        ans=0;
        cnt[1]=0;
        cnt[2]=0;
        cnt[3]=0;
        for (int i=1;i<=n;++i) if (cnt[m1[p[i]]]<m) {
            ++cnt[m1[p[i]]];
            ans+=a[p[i]][m1[p[i]]];
        }
        else {
            ++cnt[m2[p[i]]];
            ans+=a[p[i]][m2[p[i]]];
        }
        cout<<ans<<'\n';
    }
}