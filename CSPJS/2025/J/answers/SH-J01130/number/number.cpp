#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
priority_queue<int> pq;
signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if(isdigit(s[i]))
			pq.push(s[i] - '0');
	while(pq.size())
		cout << pq.top(), pq.pop();
	return 0;
}
// ÉÙÓðÅ£±Æ
