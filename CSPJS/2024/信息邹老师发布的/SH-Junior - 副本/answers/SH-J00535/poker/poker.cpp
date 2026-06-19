#include<bits/stdc++.h>
using namespace std;

int a[4][13];
string q;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n, cnt=0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> q;
        int poker_type;
        if(q[0]=='D')poker_type=0;
        else if(q[0]=='C')poker_type=1;
        else if(q[0]=='H')poker_type=2;
        else if(q[0]=='S')poker_type=3;
        if(q[1]=='T')a[poker_type][9]++;
        else if(q[1]=='J')a[poker_type][10]++;
        else if(q[1]=='Q')a[poker_type][11]++;
        else if(q[1]=='K')a[poker_type][12]++;
        else if(q[1]=='A')a[poker_type][0]++;
        else a[poker_type][q[1]-'1']++;
    }

    for(int i = 0; i <= 3; i++)
    {
        for(int j = 0; j <= 12; j++)if(!a[i][j]){cnt++;}
    }
    cout<<cnt;
    return 0;
}
