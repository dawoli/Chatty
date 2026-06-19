#include <iostream>

using namespace std;


bool q[305] = {0};

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        int m = 0;
        if(s[1] == 'A') m = 1;
        else if(s[1] == 'T') m = 10;
        else if(s[1] == 'J') m = 11;
        else if(s[1] == 'Q') m = 12;
        else if(s[1] == 'K') m = 13;
        else m = s[1] - '0';
        if(s[0] == 'D')
        {
            q[m] = true;
        }
        if(s[0] == 'C')
        {
            q[m + 13] = true;
        }
        if(s[0] == 'H')
        {
            q[m + 26] = true;
        }
        if(s[0] == 'S')
        {
            q[m + 39] = true;
        }
    }
    int cnt = 0;
    for(int i = 1;i <= 52;i++)
    {
        if(q[i] == 0) cnt++;
    }
    cout << cnt <<endl;
    return 0;
}
