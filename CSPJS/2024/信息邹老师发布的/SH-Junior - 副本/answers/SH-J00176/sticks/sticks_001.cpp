#include<bits/stdc++.h>
using namespace std;
int t;
string eight(int x)
{
	string s(x,'8');
	return s;
}
int main()
{
	freopen("sticks.in","r",stdin); //na bu fen fen
    freopen("sticks.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		switch(n%7)
		{
			case 0:
				if(n == 0)cout << -1;
				else cout << eight(n/7);
				break;
			case 1:
				if(n == 1)cout << -1;
				else cout << 10 << eight((n-8)/7);
				break;
			case 2:
				cout << 1 << eight((n-2)/7);
				break;
			case 3:
				if(n == 3)cout << 7;
				else cout << 22 << eight((n-10)/7);
				break;
			case 4:
				if(n == 4)cout << 4;
				else cout << 20 << eight((n-11)/7);
				break;
			case 5:
				cout << 2 << eight((n-5)/7);
				break;
			case 6:
				cout << 6 << eight((n-6)/7);
				break;
			default:;
		}
		cout << endl;
	}
	return 0;
}
