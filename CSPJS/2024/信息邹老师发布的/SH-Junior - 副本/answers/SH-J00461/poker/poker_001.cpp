#include <bits/stdc++.h>
using namespace std;
map <string,bool> mp;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		string POKER;
		cin >> POKER;
		mp[POKER];
	}
	printf("%d",52 - mp.size());
}
