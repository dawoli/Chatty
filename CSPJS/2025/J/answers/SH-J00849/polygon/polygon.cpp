#include <iostream>
#include <vector>
using namespace std;
const int Mod = 998244353;
const int Max = 5001;
bool polygon_check(vector<int> a(Max), int m)
{
	int sum = 0;
	int Max = a[0];
	for(int i = 0; i < m; i++)
	{
		sum += a[i];
		if(Max < a[i])
		{
			Max = a[i];
		}
	}
	if(sum > 2 * Max)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n = 0;
	cin >> n;
	vector<int> a(n);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < )
	}
	//遍历所有组合，从第一项开始，依次增加m大小，计算和，if polygon_check成立，ans++ 
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
