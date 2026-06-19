#include <bits/stdc++.h>
using namespace std;
int a[110] = {};
int n;
int num = 0;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string s;
        int ans = 0;
        cin>>s;
        if (s[0] == 'D')
        {
            ans+=0;
        }
        if (s[0] == 'C')
        {
            ans+=13;
        }
        if (s[0] == 'H')
        {
            ans+=26;
        }
        if (s[0] == 'S')
        {
            ans+=39;
        }
        if (s[1] == 'A')
        {
            ans+=1;
        }
        else if (s[1] == 'T')
        {
            ans+=10;
        }
        else if (s[1] == 'J')
        {
            ans+=11;
        }
        else if (s[1] == 'Q')
        {
            ans+=12;
        }
        else if (s[1] == 'K')
        {
            ans+=13;
        }
        else
        {
            ans+=(s[1] - '0');
        }
        a[ans] = 1;
    }
    for (int i=1;i<=52;i++)
    {
        if (a[i] == 1)
        {
            num++;
        }
    }
    cout<<52-num;
    return 0;
}
