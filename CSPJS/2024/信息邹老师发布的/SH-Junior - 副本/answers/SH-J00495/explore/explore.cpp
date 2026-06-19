#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
int n,m,k;
int dx[] = {0,1,0,-1},
    dy[] = {1,0,-1,0};
bool cal(int x,int y)
{
    if (x <= 0 || y <= 0) return false;
    if (x > n || y > m) return false;
    if (a[x][y] == 'x') return false;
    return true;
}

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    
    while (t--)
    {
    	memset(a,0,sizeof(a));
    	cin >> n >> m >> k;
    	
    	int x,y,d;
    	cin >> x >> y >> d;
    	
    	for (int i = 1;i <= n;i++)
    	{
    		for (int j = 1;j <= m;j++)
    		{
    			char s;
    			cin >> s;
    			a[i][j] = s;
			}
		}
		
    	int cnt;
    	if (cal(x + dx[d],y + dy[d])) cnt = 0;
    	else cnt = 1;
    
    	for (int i = 1;i <= k;i++)
    	{
		    if (cal(x + dx[d],y + dy[d])) 
		    {
		    	x += dx[d];
		        y += dy[d];
		        cnt++;
		       
			}
		    else
		    {
			    d = (d + 1) % 4;
			}
		}
		
		cout << cnt << endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
} 
