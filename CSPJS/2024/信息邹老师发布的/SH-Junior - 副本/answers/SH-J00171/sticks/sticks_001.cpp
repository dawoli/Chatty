#include <bits/stdc++.h>
using namespace std;
int n, T;
///// 7k /////
void solve7k()
{
	for(int i = 1; i <= (n / 7); i++)
		cout << "8";
	cout << endl;
}
///// 7k + 1 /////
void solve7kp1()
{
	int eight = n / 7 - 1;
	cout << "10";
	for(int i = 1; i <= eight; i++)
		cout << "8";
	cout << endl;
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		if(n % 7 == 0) solve7k();
		else if(n % 7 == 1) solve7kp1();
	}
	return 0;
}
