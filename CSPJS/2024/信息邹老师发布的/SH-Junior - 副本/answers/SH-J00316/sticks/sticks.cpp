#include<bits/stdc++.h>
using namespace std;
long long t, n, m, ans;
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
struct node
{
	long long st, sum, now;
};
queue <node> q;
void bfs()
{
	q.push({n, 0, 1});
	while(!q.empty())
	{
		node temp = q.front();
		q.pop();
		if(temp.st == 0)
		{
			ans = min(temp.sum, ans);
		}
		else
		{
			for(long long i = 0; i <= 9; i++)
		    {
		    	if((temp.st - num[i] == 0 && i != 0) || temp.st - num[i] > 0)
		    	{
		    		q.push({temp.st - num[i], temp.sum + temp.now * i, temp.now * 10});
				}
		    }
		}
		
	}
	
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	cin >> t;
	for(int e = 1; e <= t; e++)
	{
		ans = 1e15;
		cin >> n;
		if(n % 7 == 0)
		{
			m = n / 7;
			for(int i = 1; i <= m; i++)
	        {
	        	cout << 8;
	        }
	        cout << endl;
		}
		else if(n % 7 == 1 && n != 1)
		{
			cout << 1 << 0;
			m = (n - 8) / 7;
			for(int i = 1; i <= m; i++)
	        {
	        	cout << 8;
	        }
	        cout << endl;
		}
		else
		{
			bfs();
			if(ans == 1e15)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << ans << endl;
			}
		}
	}
	return 0;
}
