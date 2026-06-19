#include <bits/stdc++.h>
using namespace std;
int s[4][13];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        string a;cin >> a;
        int tp=0;
        if(a[0]=='D')tp=0;
        else if(a[0]=='C')tp=1;
        else if(a[0]=='H')tp=2;
        else tp=3;
        if(a[1]=='A')s[tp][0]++;
        else if('2'<=a[1]&&a[1]<='9')s[tp][a[1]-'0'-1]++;
        else if(a[1]=='T')s[tp][9]++;
        else if(a[1]=='J')s[tp][10]++;
        else if(a[1]=='Q')s[tp][11]++;
        else if(a[1]=='K')s[tp][12]++;
    }
    int ans=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            if(s[i][j]==0)ans++;
        }
    }
    cout << ans;
    return 0;
}
