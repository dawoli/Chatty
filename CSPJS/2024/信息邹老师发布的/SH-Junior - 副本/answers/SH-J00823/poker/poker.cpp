#include <iostream>
#include <string>
using namespace std;

int a[5][14];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string t;
    int n,num = 0,hs,ph;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> t;
        if (t[0] == 'D') hs = 0;
        if (t[0] == 'c') hs = 1;
        if (t[0] == 'H') hs = 2;
        if (t[0] == 'S') hs = 3;
        if (t[1] == 'A') ph = 0;
        else if (t[1] == 'T') ph = 9;
        else if (t[1] == 'J') ph = 10;
        else if (t[1] == 'Q') ph = 11;
        else if (t[1] == 'K') ph = 12;
        else ph = t[1] - 49;
        if (a[hs][ph] == 0)
        {
            a[hs][ph] = 1;
            num++;
        }
    }
    cout << 52 - num;
    return 0;
}
