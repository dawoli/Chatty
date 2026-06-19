#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000010];
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int sz = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9') a[++sz] = s[i] - '0';
    }
    sort(a + 1,a + sz + 1,cmp);
    for (int i = 1; i <= sz; i++)
        printf("%d",a[i]);
    return 0;
}
