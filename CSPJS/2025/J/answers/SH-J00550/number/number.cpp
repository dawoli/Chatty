#include <bits/stdc++.h>// 期望得分：100 
using namespace std ;

char c ;
int num_[1000005] ;
int p ;
int main()
{
	freopen("number.in", "r", stdin) ;
	freopen("number.out", "w", stdout) ;
	while (cin >> c)
	{
		if (c >= '0' && c <= '9')
		{
			num_[++p] = c - '0' ;
		}
	}
	sort(num_ + 1, num_ + p + 1, greater<int>()) ;
	for (int i = 1; i <= p; i++)
	{
		printf("%d", num_[i]) ;
	}
	return 0 ;
}

