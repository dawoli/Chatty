#include<bits/stdc++.h>
using namespace std;
char a[1000010];
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >>s;
    int cnt = 0;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i]-'0'>=0&&s[i]-'0'<=9)
        {
            a[++cnt] = s[i];
        }
    }
    sort(a+1,a+cnt+1);
    for(int i = cnt;i >= 1;i--)
    {
        cout <<a[i];
    }
    return 0;
}
