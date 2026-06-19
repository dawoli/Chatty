#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
unsigned long long mn = 2e19;
int t,n; 
int a[10000010];
bool flag = false;
void dfs(int sum,int step)
{

    if (sum > n) return;
    if (sum == n)
    {
    	unsigned long long s = 0;
    	for (int i = 1;i < step;i++)
    	{
    		int x = 0;
			if (a[i] == 2)
			{
			    x = 1;
			}
			else if (a[i] == 3)
			{
			    x = 7;
			}
			else if (a[i] == 4)
			{
			    x = 4;
			}
			else if (a[i] == 5)
			{
			    x = 2;
			}
			else if (a[i] == 6 && i == 1)
			{
			    x = 6;
			}
			else if (a[i] == 6 && i != 1)
			{
			    x = 0;
			}
			else if (a[i] == 7)
			{
			    x = 8;
			}
		
			s = s * 10 + x;
		}
		if (s < mn)
		{
			flag = true;
			mn = s;	
		}
		
		return;
	}
	for (int i = min(7,n);i >= 2;i--)
	{
		a[step] = i;
	    dfs(sum + i,step + 1);
	}
}

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
    cin >> t;
    //0:6,1:2,2:5,3:5,4:4,5:5,6:6,7:3,8:7,9:6
    while (t--)
    {
    	
    	flag = false;
    	mn = 1e18;
    	cin >> n;
    	if (n == 1)
    	{
    		cout << -1 << endl;
    		continue;
		}
    	if (n % 7 == 0)
    	{
    		for (int i = 1;i <= n / 7;i++)
    		{
    			cout << 8; 
			}
			cout << endl;
			continue;
		}
		else if (n % 7 == 1)
    	{
    		cout << 10;
    		for (int i = 1;i < n / 7;i++) cout << 8;
			cout << endl;
			continue;
		}
    	dfs(0,1);
    	if (!flag) cout << -1 << endl;
    	else cout << mn << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
		
	return 0;
	
} 
