#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, cnt;
map <string, bool> vis;
string s;
signed main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout); 
	cin >> n;
	while(n--){
		cin >> s;
		if(!vis[s]){
			cnt++;
		}
		vis[s] = 1;
	}
	printf("%lld", 52 - cnt);
	return 0;
}
