#include <iostream>
#include <cstdio>
using namespace std;
int t,n,m,l,v;
struct car
{
    int d,vv,a;
};
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> l >> v;
        int sl=0;
        car c[n+5]={};
        for(int i=1; i<=n; i++)
        {
            cin >> c[i].d >> c[i].vv >> c[i].a;
        }
        int mm=0;
        for(int i=1; i<=m; i++)
        {
            int x;
            cin >> x;
            mm=max(x,mm);
        }
        for(int i=1; i<=n; i++)
        {
            if(c[i].vv>v&&c[i].d<=mm)sl++;
        }
        cout << sl << " " << (sl!=0?m-1:m) << endl;
    }
}
