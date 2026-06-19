#include<iostream>
#include<cstdio>
using namespace std;

string s;
int a[10];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[s[i]-'0']++;
        }
    }
    bool flag = false;
    for(int i=9;i>=0;i--)
    {
        if(i!=0 && a[i]!=0)
        {
            flag = true;
        }
    }
    if(flag)
    {
        for(int i=9;i>=0;i--)
        {
            while(a[i]--)
            {
                cout << i;
            }
        }
    }
    else
    {
        cout << 0;
    }
    return 0;
}
