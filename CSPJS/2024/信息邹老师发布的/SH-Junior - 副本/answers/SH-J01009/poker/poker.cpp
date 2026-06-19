#include <iostream>
#include <string>
using namespace std;

bool A(char a[52][2], char b, char c, int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		if(a[i][0] == b && a[i][1] == c)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	int n;
	cin >> n;
	int num = n;
	
	char a[n][2];
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i][0] >> a[i][1];
		
		if(A(a, a[i][0], a[i][1], i))
		{
			num--;
		}
	}
	
	cout << 52 - num << endl;
	
	return 0;
}
