#include<iostream>
using namespace std;
int a[19][9];
int n,cnt;
int f(char c)
{
    if(c >= '2' && c <= '9')
    {
        return c - '0';
    }
    switch(c)
    {
        case 'A':
            return 1;
            break;
        case 'T':
            return 10;
            break;
        case 'J':
            return 11;
            break;
        case 'Q':
            return 12;
            break;
        case 'K':
            return 13;
            break;
        default:
            return 0;
            break;
    }
}
int g(char c)
{
    switch(c)
    {
        case 'D':
            return 0;
            break;
        case 'C':
            return 1;
            break;
        case 'H':
            return 2;
            break;
        case 'S':
            return 3;
            break;
        default:
            return 4;
            break;
    }
}
int main()
{
	// just poker no joker
    freopen("poker.in","r",stdin); //yi ding AC
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        char aa,b;
        cin >> b >> aa;
        a[f(aa)][g(b)]=true;
    }
    for(int i = 1; i <= 13; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(!a[i][j])++cnt;
        }
    }
    cout << cnt;
    return 0;
}
