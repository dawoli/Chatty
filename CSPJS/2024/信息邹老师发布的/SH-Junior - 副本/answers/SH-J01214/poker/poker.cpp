#include<bits/stdc++.h>
using namespace std;

long long cards[5][20],n;
string tn,card;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    getline(cin,tn);
    for(int i=0;i<tn.size();i++)
    {
        n=n*10+tn[i]-'0';
    }
    for(int i=1;i<=n;i++)
    {
        getline(cin,card);
        int a,b;
        if(card[0]=='D')
            a=1;
        if(card[0]=='C')
            a=2;
        if(card[0]=='H')
            a=3;
        if(card[0]=='S')
            a=4;
        if(card[1]<='9')
            b=card[1]-'0';
        if(card[1]=='A')
            b=1;
        if(card[1]=='T')
            b=10;
        if(card[1]=='J')
            b=11;
        if(card[1]=='Q')
            b=12;
        if(card[1]=='K')
            b=13;
        cards[a][b]=1;
    }
    int ans=0;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
        {
            if(cards[i][j]==0)
                ans++;
        }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
