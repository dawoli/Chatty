#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	int n, cnt = 0;
	cin >> n;
	map <string, int> a;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		a[s]++;
		if(a[s] == 1)
			cnt++;
	}
	cout << 52 - cnt << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
