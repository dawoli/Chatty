#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a[201000];
int col[201000];

void print(int i, int ans)
{
	for(int k = 0; k<=i; k ++)
	{
		cout << col[k] << ' '; 
	}
	cout << endl;
	cout << i << ' ' << ans;
	cout << endl;
}
int sol(int i, int color, int ans)
{
	
	col[i] = color;
	int k = i-1;
	while(k >= 0)
	{
		if(col[i] == col[k])
		{
			if(a[i] == a[k])
			{
				ans+=a[i];
				
			}
			break;
		}
		k--;
	}
	if(i >= n) return ans;
//	print(i ,ans);
	return max(sol(i+1, 1, ans), sol(i+1, 0, ans));
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
    cin >> T;
	while(T--)
	{
	
		cin >> n;
		for(int i = 0; i < n; i ++)
		{
			cin >> a[i];
		}
		cout << max(sol(0, 0, 0), sol(0, 1, 0)) << endl;
		
	}
	return 0;
}
