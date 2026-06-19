#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n;
    cin>>n;
    bool x[6][15] = {};
    for(int i = 0; i<n; i++)
    {
        char a,b;
        int tmp1, tmp2=-1;
        cin>>a>>b;
        switch(a){ // D=1,C=2,H=3,S=4
            case 'D':
                tmp1 = 1;
                break;
            case 'C':
                tmp1 = 2;
                break;
            case 'H':
                tmp1 = 3;
                break;
            case 'S':
                tmp1 = 4;
                break;
        }
        switch(b){ // T=10,J=11,Q=12,K=13
            case 'A':
                tmp2 = 1;
                break;
            case 'T':
                tmp2 = 10;
                break;
            case 'J':
                tmp2 = 11;
                break;
            case 'Q':
                tmp2 = 12;
                break;
            case 'K':
                tmp2 = 13;
                break;
        }
        if (tmp2==-1){ // other b
            tmp2 = b - '0';
        }
        x[tmp1][tmp2] = true;
    }

    int ans = 0;
    for(int i = 1; i<=4; i++)
        {
        for(int j = 1; j<=13; j++)
        {
            if (!x[i][j])
            {
                ans++;
            }
        }
    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
