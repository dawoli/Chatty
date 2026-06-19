#include <bits/stdc++.h>
using namespace std;
int n;

int cal(int n)
{
	if(n == 1) return -1;
	if(n == 2) return 1;
	if(n == 3) return 7;
	if(n == 4) return 4;
	if(n == 5) return 2;
	if(n == 6) return 6;
	if(n == 7) return 8;
	for(int i = 2; i <= n; i ++)
	{
		int i2 = n - i;
		int a = cal(i),b = cal(i2);
		if(a != -1 && b != -1) return (10 * a + b);
	}
	return -1;
}
int a[55];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++)
	{
		int x;
		scanf("%d",&x);
		a[i] = x;
	}
	for(int i = 1; i <= n; i ++)
	{
		int m = cal(a[i]);
		printf("%d\n",m);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
