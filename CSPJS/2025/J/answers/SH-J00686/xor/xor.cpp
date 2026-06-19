#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector <pair<int,int>> v;
int a[500005];
int pre[500005];
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a.second < b.second;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		pre[i] = (pre[i-1] ^ a[i]);
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			if ((pre[j] ^ pre[i-1]) == k)
			{
				v.push_back({i,j});
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	int lastr = -1;
	int ans = 0;
	for (pair<int,int> lr : v)
	{
		if (lr.first > lastr)
		{
			ans++;
			lastr = lr.second;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
1 0
  1
  0
1 1
4 0
2 1 0 3
*/
