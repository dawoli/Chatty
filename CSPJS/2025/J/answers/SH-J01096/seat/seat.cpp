#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	int seat = 0;
	int arr[n * m];
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> arr[i * n + j];
		}
	}
	int temp = arr[0];
	
	sort(arr, arr + n * m);
	for(int i = n * m - 1; i >= 0; i--)
	{
		if(arr[i] == temp) break;
		else seat++;
	}
	
	if((seat / n) % 2 == 0)
	{
		cout << seat / n + 1 << " " << seat % n + 1;
	}
	else
	{
		cout << seat / n + 1 << " " << n - seat % n;
	}
	
	return 0;
}
