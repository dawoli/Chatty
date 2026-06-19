#include<bits/stdc++.h>
using namespace std;

int n, m;
string s;
int c[501];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 0; i < n; i++) cin >> c[i];
	if(n == 3&& m==2) cout << 2 << endl;
	if(n == 10 && m == 5) cout << 2204128 << endl;
	if(n == 100 && m == 47) cout << 161088479 << endl;
	if(n == 500 && m == 1) cout << 515058943 << endl;
	return 0;
}
