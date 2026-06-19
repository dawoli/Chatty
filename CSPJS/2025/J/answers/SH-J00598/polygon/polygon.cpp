#include <bits/stdc++.h>
using namespace std;
bool tri(int a , int b , int c)
{
	if((a + b + c) > 2 * max(max(a , b) , c))return 1;
	return 0;
}
signed main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout); 
	int n;
	cin >> n;
	int a , b , c;
	if(n >= 3) cin >> a >> b >> c;
	else
	{
		cout << 0;
		return 0;
	}
	if(tri(a , b , c)) cout << 1;
	else cout << 0;
	return 0;
}
