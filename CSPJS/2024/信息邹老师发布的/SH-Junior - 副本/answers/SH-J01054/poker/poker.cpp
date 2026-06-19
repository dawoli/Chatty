#include <iostream>
#include <cstdio>
using namespace std;
int n,ans=52;
bool a[52];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int x1,x2;
        if (s[0]=='C') x1=0;
        else if (s[0]=='D') x1=1;
        else if (s[0]=='H') x1=2;
        else x1=3;
        if (s[1]=='A') x2=0;
        else if (s[1]=='T') x2=9;
        else if (s[1]=='J') x2=10;
        else if (s[1]=='Q') x2=11;
        else if (s[1]=='K') x2=12;
        else x2=s[1]-'0'-1;
        a[13*x1+x2]=true;
    }
    for (int i=0;i<52;i++) if (a[i]) ans--;
    printf("%d",ans);
    return 0;
}
