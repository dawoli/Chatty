#include <bits/stdc++.h>
using namespace std;
const int N = 109;
int n;
map<char, int> po;
set<int> D;
set<int> C;
set<int> H;
set<int> S;
struct Poker
{
	char h; int p;
} poker[N];
void init()
{
	po['A'] = 1;
	po['2'] = 2;
	po['3'] = 3;
	po['4'] = 4;
	po['5'] = 5;
	po['6'] = 6;
	po['7'] = 7;
	po['8'] = 8;
	po['9'] = 9;
	po['T'] = 10;
	po['J'] = 11;
	po['Q'] = 12;
	po['K'] = 13;
}
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	init();
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		string t;
		cin >> t;
		poker[i].h = t[0]; poker[i].p = po[t[1]];
		switch(t[0])
		{
			case 'D': D.insert(po[t[1]]); break;
			case 'C': C.insert(po[t[1]]); break;
			case 'H': H.insert(po[t[1]]); break;
			case 'S': S.insert(po[t[1]]); break;
		}
	}
	int ans = 0;
	ans += D.size();
	ans += C.size();
	ans += H.size();
	ans += S.size();
	cout << 52 - ans << endl;
	return 0;
}
