#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;


int arr[100005][4];
int maxn = -1;
		int n;
void dfs(int a,int b,int c,int sum,int step)
{
	if (step > n)
		maxn = max(maxn,sum);
	if (a < n/2)
	{
		dfs(a+1,b,c,sum+arr[step][1],step+1);
	}
	if (b < n/2)
	{
		dfs(a,b+1,c,sum+arr[step][2],step+1);
	}
	if (c < n/2)
	{
		dfs(a,b,c+1,sum+arr[step][3],step+1);
	}
} 
int main()
{
	freopen("club.in","r",stdin); 
		freopen("club.out","w",stdout); 
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= 3;j++)
			{
				arr[i][j] = 0;
			}
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= 3;j++)
			{
				int t;
				cin >> t;
				arr[i][j] = t;
			}
		}
		maxn = -1;
		dfs(0,0,0,0,1) ;
		cout << maxn << endl; 
	} 
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

