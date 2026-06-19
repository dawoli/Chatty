#include <iostream>
#include <string>
using namespace std;

bool vis[10][20]; // 花色-点数
int a[256];
int b[256];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    a['D'] = 1;
    a['C'] = 2;
    a['H'] = 3;
    a['S'] = 4;

	b['A'] = 1;
    b['T'] = 10;
    b['J'] = 11;
    b['Q'] = 12;
    b['K'] = 13;
    for(int i = 1;i<=n;i++)
    {
        string s;
        cin>>s;
        char points = s[1];
        int p;
        if ('A' <= points && points <= 'Z')
        {
            p = b[points];
        }  
        else
        {
            p = points-'0';
        }
        vis[a[s[0]]][p] = 1;
    }

    int cnt = 0;
    for(int i = 1;i<=4;i++)
    {
        for(int j = 1;j<=13;j++)
        {
            cnt += !vis[i][j];
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}