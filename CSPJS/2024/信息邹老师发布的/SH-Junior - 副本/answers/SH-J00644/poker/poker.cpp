#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
set<string> s; 
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans = 52;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		string a;
		cin >> a;
		ans -= s.insert(a).second;
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
