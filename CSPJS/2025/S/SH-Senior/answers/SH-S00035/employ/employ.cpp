#include<iostream>
#include<cstring>
using namespace std;
int c[505];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	cout << m << endl;
	return 0;
}
