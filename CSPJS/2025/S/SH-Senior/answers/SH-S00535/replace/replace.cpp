#include <bits/stdc++.h>
#define ui unsigned int
#define ull unsigned long long
#define ll long long
#define MXN 200005
using namespace std;
int n, q;
bool flg;
string S[2], T[2];
int s[2 * MXN], t;
int f(string str)
{
	for(ui i = 0; i < str.length(); i++)
		if(str[i] == 'b')
			return i;
	flg = 1;
	return 0;
}
int main()
{
	//freopen("replace.in", "r", stdin);
	//freopen("replace.out", "w", stdout);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	//for(int i = 1; i <= n; i++)
		//cin >> S[0] >> S[1],
		//s[f(S[0]) - f(S[1]) + MXN]++;
	for(int i = 1; i <= q; i++)
	{
		//cin >> T[0] >> T[1], 
		//t = f(T[0]) - f(T[1]);
		//if(!flg)
		//	cout << s[t + MXN] << endl;
		//else
			cout << 0 << endl;
	}
	return 0;
}

