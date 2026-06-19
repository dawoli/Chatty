#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
	return a > b; 
} 

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int arr[1005], a = 0;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			arr[a] = s[i] - 48;
			a++;
		}
	}
	sort(arr, arr + a, cmp);
	for (int j = 0; j < a; j++)
	{
		cout << arr[j];
	}
	return 0;
}
