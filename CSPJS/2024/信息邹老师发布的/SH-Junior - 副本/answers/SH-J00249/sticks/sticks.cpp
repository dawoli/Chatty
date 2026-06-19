#include<bits/stdc++.h>
using namespace std;

const int stick[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void doit(int n)
{
	if(n < 2)
	{
		cout << -1 << '\n';
	    return;
	}
	switch(n)
	{
		case 2:
			cout << 1 << '\n';
			return;
		case 3:
			cout << 7 << '\n';
			return;
		case 4:
			cout << 4 << '\n';
			return;
		case 5:
			cout << 2 << '\n';
			return;
		case 6:
			cout << 6 << '\n';
			return;
		case 7:
			cout << 8 << '\n';
			return;
		default:
			break;
	}
	if(n % 7 == 0)
	{
		for(int i = 0;i < n / 7;i++)
		    cout << 8;
		cout << '\n';
		return;
	}
	int ys = 7 + n % 7;
	if(ys == 8)
		cout << 10;
	else if(ys == 9)
		cout << 18;
	else if(ys == 10)
		cout << 22;
	else if(ys == 11)
		cout << 20;
	else if(ys == 12)
		cout << 28;
	else if(ys == 13)
		cout << 68;
	for(int i = 0;i < (n - ys) / 7;i++)
		cout << 8;
	cout << '\n';
}
int main()
{
	int t;
	vector<int> input;
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		input.push_back(n);
	}
	for(int i = 0;i < input.size();i++)
	    doit(input[i]);
	
	return 0;
}
