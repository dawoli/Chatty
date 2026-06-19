#include <bits/stdc++.h>
using namespace std;
int n, a[100015], pos[100015], ans, pos_[100015];
bool exist[100015], con[100015];
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	pos_[0] = pos[0] = 100010;
	pos_[100010] = -1;
	for(int i = 1; i < n; i++)
	{
		if(a[i] != a[i-1])
			pos[i] = i-1;
		else
			pos[i] = pos[i-1];
		pos_[i] = pos[i];
	}
	
    for(int i = 0; i < n; i++)
    {
    	while(exist[pos_[i]] == 1 && pos_[i] >= -1) pos_[i]--;
    	if(pos[i] == pos[i+1]) pos_[i+1] = pos_[i]-1;
    	if(exist[i] == 0 && pos_[i] >= 0)
		{
    		con[i] = 1;
    		exist[pos_[i]] = 1;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		if(exist[i] == 0) ans++;
	}
	cout << ans;
	
	return 0;
}
