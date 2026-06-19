#include <bits/stdc++.h>

using namespace std; 

int main()
{
	freopen("chain.in", "r", stdin); 
	freopen("chain.out", "w", stdout); 
	srand(time(0)); 
	int t; 
	cin >> t; 
	while(t--)
	{
		int n; 
		cin >> n; 
		while(n--)
		{
			cout << rand() % 2 << endl; 
		}
	}
	return 0; 
}
