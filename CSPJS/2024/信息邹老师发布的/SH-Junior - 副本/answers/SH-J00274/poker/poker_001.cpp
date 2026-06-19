#include <iostream>
#include <bits/stdc++.h>
#define N 53

using namespace std;

long long sume;
long long ans;
int pocker[N][N]={0};

struct card
{
    char typ;
    char numbr;
};
card c[N];

int main()
{
    freopen("pocker.in","r",stdin);
    freopen("pocker.out","w",stdout);

    cin>>sume;

    for(int i=1;i<=sume;i++)
    {
        cin>>c[i].typ>>c[i].numbr;

        if(pocker[c[i].typ-'0'][c[i].numbr-'0'] == 0)
        {
            pocker[c[i].typ-'0'][c[i].numbr-'0']++;
            ans++;
        }
    }

    cout<< 52 - ans <<endl;

    return 0;
}
