#include <iostream>
#include <algorithm>
using namespace std;

int N[6] = {7, 6, 5, 4, 3, 2};
int S[6] = {1, 7, 4, 2, 6, 8};

void stick(int n)
{
	if(n < 2)
	{
		cout << -1 << endl;
		return;
	}
	
	int temp = 1, num = 0;
	
	if(n <= 7)
	{
		num = S[n - 2];
	}
	else if(n % 7 == 0)
	{
		for(int i = 0; i < n / 7; i++)
		{
			num += 8 * temp;
			temp *= 10;
		}
	}
	else
	{
		int m = n / 7 + 1;
		int a[n], aTemp = 0;
		
		while(n >= 14)
		{
			n -= 7;
			a[aTemp] = 8;
			aTemp++;
		}
		
		if(n == 8)
		{
			a[aTemp++] = 1;
			a[aTemp] = 6;
		}
		else if(n == 9)
		{
			a[aTemp++] = 1;
			a[aTemp] = 6;
		}
		else if(n == 10)
		{
			a[aTemp++] = 4;
			a[aTemp] = 0;
		}
		else if(n == 11)
		{
			a[aTemp++] = 2;
			a[aTemp] = 0;
		}
		else if(n == 12)
		{
			if(aTemp == 0)
			{
				a[aTemp++] = 2;
			    a[aTemp] = 8;
			}
			else
			{
				a[aTemp++] = 0;
			    a[aTemp] = 0;
			}
		}
		else if(n == 13)
		{
			a[aTemp++] = 0;
			a[aTemp] = 8;
		}
		
		sort(a, a + aTemp + 1);
		int aTemp2 = 0;
		while(a[0] == 0)
		{
			swap(a[aTemp2], a[aTemp2++]);
		}
		
		for(int i = aTemp; i >= 0; i--)
		{
			num += a[i] * temp;
			temp *= 10;
		}
	}
	cout << num << endl;
}

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	int T;
	cin >> T;
	
	int n;
	for(int i = 0; i < T; i++)
	{
		cin >> n;
		stick(n);
	}
	
	return 0;
}
