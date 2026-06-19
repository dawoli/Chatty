#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int b[1000005];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
    }
    cout << 2 << endl;
    int idx=-1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<b[i])
        {
            idx=1;
            break;
        }
    }
    if(idx==1)
    {
        for(int i=1;i<=n;i++)
        {
            cout << a[i] << ' ';
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            cout << b[i] << ' ';
        }
    }
    return 0;
}
