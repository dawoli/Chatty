#include <bits/stdc++.h>
using namespace std;
string s;
int n,a[1000005];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]<='9'&&s[i]>='0')
        {
            a[n]=s[i]-'0';
            n++;
        }
    }
    sort(a,a+n,cmp);
    for (int i=0;i<n;i++)
        cout <<a[i];
    return 0;
}
