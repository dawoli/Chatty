#include <bits/stdc++.h>
using namespace std;
char a[15]={'A','1','2','3','4','5','6','7','8','9','T','J','Q','K'},b[15]={'A','1','2','3','4','5','6','7','8','9','T','J','Q','K'};
char c[15]={'A','1','2','3','4','5','6','7','8','9','T','J','Q','K'},d[15]={'A','1','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(s[0]=='D')
        {
            for(int j=0;j<=12;j++)
            {
                if(a[j]==s[1])
                {
                    a[j]='0';
                    break;
                }
            }
        }
        if(s[0]=='C')
        {
            for(int j=0;j<=12;j++)
            {
                if(b[j]==s[1])
                {
                    b[j]='0';
                    break;
                }
            }
        }
        if(s[0]=='H')
        {
            for(int j=0;j<=12;j++)
            {
                if(c[j]==s[1])
                {
                    c[j]='0';
                    break;
                }
            }
        }
        if(s[0]=='S')
        {
            for(int j=0;j<=12;j++)
            {
                if(d[j]==s[1])
                {
                    d[j]='0';
                    break;
                }
            }
        }

    }
    int cnt=0;
    for(int i=0;i<=12;i++)
    {
        if(a[i]!='0')
        {
            cnt++;
        }
        if(b[i]!='0')
        {
            cnt++;
        }
        if(c[i]!='0')
        {
            cnt++;
        }
        if(d[i]!='0')
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
