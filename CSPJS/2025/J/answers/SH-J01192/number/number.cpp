#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int b[1000005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cur=0;
    for(int i=0;i<s.size();i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            cur++;
            b[cur]=int(s[i])-'0';
        }
    }
    sort(b+1,b+cur+1,cmp);
    for(int i=1;i<=cur;i++)cout<<b[i];
    return 0;
}
