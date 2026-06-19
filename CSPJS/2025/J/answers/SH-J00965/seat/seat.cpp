#include <bits/stdc++.h>
using namespace std;
int n,m;
struct P
{
    int pos,score;
}a[101];
bool cmp(P a,P b)
{
    return a.score>b.score;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out""w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i].score;
        a[i].pos=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int pos;
    for (int i=1;i<=n*m;i++)
    {
        if (a[i].pos==1)
        {
            pos=i;
            break;
        }
    }
    if (pos%n==0)
    {
        if ((pos/n)%2==0)
            cout << pos/n<<" "<<1;
        else
            cout << pos/n<<" "<<n;
    }
    else
    {
        if ((pos/n)%2==0)
            cout << pos/n+1<<" "<<pos%n;
        else
            cout << pos/n+1<<" "<<n-pos%n+1;
    }
    return 0;
}
