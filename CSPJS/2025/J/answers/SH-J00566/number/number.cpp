#include <bits/stdc++.h>

using namespace std; 

char a[1000005]; 
int b[1000005]; 

int main()
{
	freopen("number.in", "r", stdin); 
	freopen("number.out", "w", stdout); 
	cin >> a; 
	int l = strlen(a); 
	int cnt = 0; 
	for(int i = 0; i < l; i++)
	{
		if(a[i] >= '0' && a[i] <= '9')
		{
			b[++cnt] = (a[i] - '0'); 
		}
	}
	sort(b + 1, b + cnt + 1); 
	for(int i = cnt; i >= 1; i--)
	{
		cout << b[i]; 
	}
	return 0; 
}
