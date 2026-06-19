#include <bits/stdc++.h>
using namespace std;
int a[11];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int si =(int)s.size();

    for(int i=0;i<=si;i++)
    {
        if(s[i]>=48&&s[i]<=57)
        {
            a[(s[i])-48]++;
        }

    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=a[i];j++)
        {
            cout<<i;
        }

    }
}
