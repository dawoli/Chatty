#include <iostream>
using namespace std;

int T,n;
int stick_num[10] = {6,2,5,5,4,5,6,3,7,6};
inline void solve()
{
	cin >> n;
	int u = n%7;
	int k = n/7;
	string ans = "";
	
	if(k == 0)
	{
		for(int i = 1;i<=9;i++)
		{
			if(u == stick_num[i])
			{
				ans = ans + (char)(i + '0');
				break;
			}
		}
	}
	
	else if(u == 0)
	{
		for(int i = 1;i<=k;i++) ans = ans + '8';
	}
	else if(u == 1)
	{
		ans = ans + "10";
		k--;
		for(int i = 1;i<=k;i++) ans = ans + '8';
	}
	else if(u == 2) 
	{
		ans = ans + "18";
		k--;
		for(int i = 1;i<=k;i++) ans = ans + '8';
	}
	else if(u == 3) 
	{
		if(k == 1) ans = ans + "22";
		else
		{
			ans = ans + "200";
			k-=2;
			for(int i = 1;i<=k;i++) ans = ans + '8';
		}
		
	}
	else if(u == 4) 
	{
		ans = ans + "20";
		k--;
		for(int i = 1;i<=k;i++) ans = ans + '8';
	}
	else if(u == 5) 
	{
		ans = ans + "28";
		k--;
		for(int i = 1;i<=k;i++) ans = ans + '8';
	}
	else if(u == 6) 
	{
		ans = ans + "68";
		k--;
		for(int i = 1;i<=k;i++) ans = ans + '8';
	}
	
	if(ans == "") cout << -1 << '\n';
	else cout << ans << '\n';
	
}

int main()
{
	freopen("sticks.in" , "r" , stdin);
	freopen("sticks.out" , "w" , stdout);
	cin >> T;
	while(T--)
	{
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
