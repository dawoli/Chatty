#include<bits/stdc++.h>

using namespace std; 

int t; 
int n; 
int a[100005][3]; 
bool flagA = true; 

int main()
{
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout); 
	cin >> t; 
	while(t--)
	{
		cin >> n; 
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3]; 
			if(a[i][2] != 0 && a[i][3] != 0)
			{
				flagA = false; 
			}
		}
		if(flagA)
		{
			sort(a[1] + 1, a[1] + n + 1); 
			int ans = 0; 
			for(int i = (n / 2 + 1); i <= n; i++)
			{
				ans += a[i][1]; 
			}
			cout << ans << endl; 
		}
		else
		{
			cout << 0 << endl; 
		}
	}
	return 0; 
}
