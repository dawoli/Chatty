#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
string s;
int a[1000000],cnt;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cnt=-1;

    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            cnt++;
            a[cnt]=s[i]-'0';
        }
    }
    sort(a,a+cnt+1);
    for(i=cnt;i>=0;i--)
    {
        cout<<a[i];
    }
    return 0;
}
