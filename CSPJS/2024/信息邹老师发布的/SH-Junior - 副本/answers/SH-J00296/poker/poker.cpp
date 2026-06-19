#include <iostream>
using namespace std;
int joker[4][15], n;
void sol1()
{
	int cnt = 0;
    for (int i = 0; i < n; i ++)
    {
        string s;
        cin >> s;
        int c;
        if (s[0] == 'D')
        {
            c = 0;
        }
        else if (s[0] == 'C')
        {
            c = 1;
        }
        else if (s[0] == 'H')
        {
            c = 2;
        }
        else
        {
            c = 3;
        }
        if ('2' <= s[1] && s[1] <= '9')
        {
            joker[c][s[1] - '0'] = 1;
        }
        else if (s[1] == 'A')
        {
            joker[c][1] = 1;
        }
        else if (s[1] == 'T')
        {
            
            joker[c][10] = 1;
        }
        else if (s[1] == 'J')
        {
            joker[c][11] = 1;
        }
        else if (s[1] == 'Q')
        {
            joker[c][12] = 1;
        }
        else
        {
        	joker[c][13] = 1;
        }
    }
    for (int i = 0; i < 4; i ++)
	{
		for (int j = 1; j <= 13; j ++)
		{
			if (!joker[i][j])
			{
				cnt ++;
			}
		}
	} 
	printf("%d", cnt);
}
void sol2()
{
	int cnt = 52;
    for (int i = 0; i < n; i ++)
    {
        string s;
        cin >> s;
        int c;
        if (s[0] == 'D')
        {
            c = 0;
        }
        else if (s[0] == 'C')
        {
            c = 1;
        }
        else if (s[0] == 'H')
        {
            c = 2;
        }
        else
        {
            c = 3;
        }
        if ('2' <= s[1] && s[1] <= '9')
        {
        	if (!joker[c][s[1] - '0'])
        	{
        		cnt --;
        		joker[c][s[1] - '0'] = 1;
			}
        }
        else if (s[1] == 'A')
        {
            if (!joker[c][1])
        	{
        		cnt --;
        		joker[c][1] = 1;
			}
        }
        else if (s[1] == 'T')
        {
            if (!joker[c][10])
        	{
        		cnt --;
        		joker[c][10] = 1;
			}
        }
        else if (s[1] == 'J')
        {
            if (!joker[c][11])
        	{
        		cnt --;
        		joker[c][11] = 1;
			}
        }
        else if (s[1] == 'Q')
        {
            if (!joker[c][12])
        	{
        		cnt --;
        		joker[c][12] = 1;
			}
        }
        else
        {
        	if (!joker[c][13])
        	{
        		cnt --;
        		joker[c][13] = 1;
			}
        }
    }
    printf("%d", cnt);
}
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
    cin >> n;
    sol2();
    return 0;
}
