#include<bits/stdc++.h>
using namespace std;
bool vis[128];
int main()
{
	int n, ct = 0;
	char c;
	cin >> n;
	while(n--)
	{
		cin >> c;
		vis[c] = true;
	}
	for(char i = 'a'; i <= 'z'; ++i)
		if(!vis[i])
			ct++;
	cout << ct;
	return 0;
}

