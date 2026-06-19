#include <bits/stdc++.h> // 期望得分：40 
using namespace std ;

int n ;
int stk[5005] ;
int ps[5005] ;
int cnt = 0 ;
int sum ;
void dfs(int s)
{
	if (s > n)
	{
		return ;
	}
	if (s >= 4)
	{
		cnt = 0 ; 
		for (int i = 1; i <= s - 1; i++)
		{
			cnt += stk[ps[i]] ;
		} 
		if (cnt > 2 * stk[ps[1]])
		{
			sum++ ;
			sum %= 998244353 ;
		}
	}
	for (int i = ps[s - 1] + 1; i <= n; i++)
	{
		ps[s] = i ;
		dfs(s + 1) ;
		ps[s] = 0 ;
	}
	return ;
}
int main()
{
	freopen("polygon.in", "r", stdin) ;
	freopen("polygon.out", "w", stdout) ;
	scanf("%d", &n) ;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &stk[i]) ;
	}
	sort(stk + 1, stk + n + 1, greater<int>()) ;
	dfs(1) ;
	printf("%d", sum + 1) ;
	return 0 ;
}

