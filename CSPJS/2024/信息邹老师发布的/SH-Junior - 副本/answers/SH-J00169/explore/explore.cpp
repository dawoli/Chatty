#include <iostream>
using namespace std;
int T, n, m, k, xC, yC, dC, exp; string map;
int world[1005][1005], explored[1005][1005];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
	cin >> T;
    for (int i=1; i<=T; i++)
    {
    	exp =0;
		if (i>1)
    	{
    		
    		for (int o=1; o<= n; o++)
        {
        	for (int p=1; p<=m; p++)
        	{
        		world[o][p] = 0;
        		explored[o][p]=0;
			}
		}
		}
        cin >> n >> m >> k;
        cin >> xC >> yC >> dC;
        for (int j=1; j<=n; j++)
        {
            cin >> map;
            for (int k=1; k<=m; k++)
            {
                if (map[k-1] == '.') world[j][k] = 1;
                else if (map[k-1] == 'x') world[j][k] = 2;
            }
        }
        //game innit
		explored[xC][yC] = 1;
        for (int l=1; l<=k; l++) //explore start
        {
            if (dC == 0)
            {
                if (world[xC][yC+1] == 1) yC++;
                else dC = (dC+1)%4;
            }
            else if (dC == 1)
            {
                if (world[xC+1][yC] == 1) xC++;
                else dC = (dC+1)%4;
            }
            else if (dC == 2)
            {
                if (world[xC][yC-1] == 1) yC--;
                else dC = (dC+1)%4;
            }
            else
            {
                if (world[xC-1][yC] == 1) xC--;
                else dC = (dC+1)%4;
            }
            explored[xC][yC] = 1;
        }
        for (int o=1; o<= n; o++)
        {
        	for (int p=1; p<=m; p++)
        	{
        		if (explored[o][p] == 1)
        		exp++;
			}
		}
		cout << exp << endl;
		exp=0;
    }
    return 0;
} 
