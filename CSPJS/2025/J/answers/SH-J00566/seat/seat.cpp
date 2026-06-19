#include <bits/stdc++.h>

using namespace std; 

int n, m; 
int a[105]; 

int main()
{
	freopen("seat.in", "r", stdin); 
	freopen("seat.out", "w", stdout); 
	cin >> n >> m; 
	for(int i = 1; i <= (n * m); i++)
	{
		cin >> a[i]; 
	}
	int se = a[1]; 
	sort(a + 1, a + (n * m) + 1); 
	int ind = 0; 
	for(int i = 1; i <= (n * m); i++)
	{
		if(a[i] == se)
		{
			ind = ((n * m) - i + 1); 
			break; 
		}
	}
	cout << (((ind - 1) / n) + 1) << ' '; 
	if((((ind - 1) / n) + 1) % 2 == 0)
	{
		cout << (n - (ind % n) + 1); 
	}
	else
	{
		cout << ((ind % n) == 0 ? n : (ind % n)); 
	}
	return 0; 
}
