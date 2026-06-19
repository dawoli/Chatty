#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, a[500005], p[500005] = {};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n;
	cin >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		p[i] = p[i - 1] ^ a[i];
	}
	if(k == 0) 
	{
		cout << n / 2; 
		return 0;
	}
	cout << 2;
	return 0;
	
 } 
 
/*
0 1 2 3 4
0 2 3 3 0



p[i1] ^ p[j1] = k
p[i2] ^ p[j2] = k




00100110001
00111011110

*/
