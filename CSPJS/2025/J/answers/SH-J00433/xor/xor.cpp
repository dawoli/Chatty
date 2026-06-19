#include <iostream>
#include <cstdio>
using namespace std;
long long a[500005];
bool satisfied = true;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >> n >> k;
	int a1 = 0;
	int a0 = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		if (a[i] == 1) a1++;
		else if(a[i] == 0) a0++; 
	}
	if(k == 0 && a1 == n) cout << n / 2;
	else if(k == 1 && a1 == n) cout << n;
	else if(k == 0 && a0 == n) cout << n;
	else if(k == 1 && a1 != n && a0 != n) cout << a1;
	else if(k == 0 && a1 != n && a0 != n) cout << a1/2 + a0;
	else
	{
		//Ê²Ã´¹íÌâ
		satisfied = false;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
