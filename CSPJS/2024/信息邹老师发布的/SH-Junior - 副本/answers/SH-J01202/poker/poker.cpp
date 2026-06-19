#include <iostream>
#include <cstdio>
#include <string>
#define int long long 
using namespace std;
int n, p[5][15], cnt;
string s;
signed main()
{
	freopen("poker.in", "r", stdin); 
	freopen("poker.out", "w", stdout); 
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        int t = s[1] - '0';
        if(s[1] == 'A')t = 1;
        if(s[1] == 'T')t = 10;
        if(s[1] == 'J')t = 11;
        if(s[1] == 'Q')t = 12;
        if(s[1] == 'K')t = 13;
        if(s[0] == 'D')p[1][t]++;
        if(s[0] == 'C')p[2][t]++;
        if(s[0] == 'H')p[3][t]++;
        if(s[0] == 'S')p[4][t]++;
    }
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 13; j++)
            if(!p[i][j])cnt++;
    cout << cnt << endl;
    return 0;
}
