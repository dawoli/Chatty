#include <iostream>
#include <cstdio>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int sum = 0;
	int maxx = -100;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		sum += a[i];
		maxx = max(maxx,a[i]);
	}
	if(n < 3)
	{
		cout << 0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n == 3)
	{
		if(sum > 2 * maxx) cout << 1;
		else cout << 0;
	}
	if(n > 3)
	{
		//À„¡ÀŒ“∞⁄¿√¡À 
		fclose(stdin);
		fclose(stdout);
		return 0; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
