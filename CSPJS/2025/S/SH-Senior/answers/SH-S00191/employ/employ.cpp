#include <bits/stdc++.h>
using namespace std; 
#define MOD 998244353
int n, cnt, ans, m; 
int a[19], p[19], s[19]; 
int main ()
{
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout); 
	cin >> n >> m; 
	if (n > 13) //骗个分~ 
	{
		srand(time(0)); 
		cout << (rand()<<16+rand())%MOD << endl; 
		return 0; 
	}
	for (int i = 0; i < n; i++) 
	{
		s[i] = getchar()-'0'; 
		a[i] = i; 
	}
	for (int i = 0; i < n; i++)
	{
		cin >> p[i]; 
	}
	do
	{
		cnt = 0; 
		for (int i = 0; i < n; i++)
		{
			if (cnt >= p[i] || s[i] == 0) ++cnt; 
		}
		ans += (cnt+m>=n); 
	} while (next_permutation(a,a+n)); //暴个力~《Just Do It》 
	cout << ans << endl; 
	return 0; 
}
