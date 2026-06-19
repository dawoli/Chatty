#include <bits/stdc++.h>
using namespace std;
int frq;
int n;
map <int,int> mp;
int digit(int x)
{
	if(x < 0) return 1e9;
	int l = 0,r = 12600;
	int best = 1e9;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(mid * 7 >= x) 
		{
			r = mid - 1;
			best = mid;
		}
		else l = mid + 1;
	}
	return best;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&frq);
	mp[0] = 6;
	mp[1] = 2;
	mp[2] = 5;
	mp[3] = 5;
	mp[4] = 4;
	mp[5] = 5;
	mp[6] = 6;
	mp[7] = 3;
	mp[8] = 7;
	mp[9] = 6;
	while(frq--)
	{
		scanf("%d",&n);
		if(n == 1)
		{
			cout << -1 << endl;
			continue;
		}
		int dig = digit(n); 
		int left = n;
		for(int t = 1;t <= dig;t++)
		{
			int i = 0;
			if(t == 1) i = 1;
			for(;i <= 9;i++)
			{
				//cout << digit(left - mp[i])<< " "<< dig - t << endl;
				if(left - mp[i] != 1 && left - mp[i] <= (dig - t) * 7 && digit(left - mp[i]) <= dig - t)
				{
					break;
				}
			}
			left -= mp[i];
			cout << i;
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
