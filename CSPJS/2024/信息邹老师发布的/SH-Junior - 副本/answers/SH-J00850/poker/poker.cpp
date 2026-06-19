#include<iostream>
using namespace std;

int a[5][20];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin >> c;
        char num;
        cin >> num;
        int x;
        if(num=='A') x=1;
        else if(num=='T') x=10;
        else if(num=='J') x=11;
        else if(num=='Q') x=12;
        else if(num=='K') x=13;
        else x=num-'0';
        if(c=='D')
        {
            a[1][x]++;
        }
        else if(c=='C')
        {
            a[2][x]++;
        }
        else if(c=='H')
        {
            a[3][x]++;
        }
        else
        {
            a[4][x]++;
        }
    }
    int cnt=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(a[i][j]==0) cnt++;
        }
    }
    cout << cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
