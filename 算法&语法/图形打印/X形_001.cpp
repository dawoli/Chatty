#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int i=0;
	int j=0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i==j||i + j == n+1)cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
	return 0;
}
