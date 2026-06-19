#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
map<string,bool> flag;
signed main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string s;
	cin >> n;
	for(int i = 1;i <= n;i++)	
	{
		cin >> s;
		flag[s] = true;
	}
	cout << 52 - flag.size() << endl;
	return 0;
}

