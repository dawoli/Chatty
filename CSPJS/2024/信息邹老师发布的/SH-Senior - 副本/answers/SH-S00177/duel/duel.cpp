#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6+5;
int n;
int r[maxn];
int ans;
bool isdie[maxn];
bool fl[maxn];
bool isend = true;

int main ()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	//memset(isdie, 0, sizeof(isdie));
	//memset(fl, 0, sizeof(fl));
	cin >> n;
	ans = n;
	for (int i = 1; i <= n; i++)
	{
		cin >> r[i];
	}
	sort(r+1, r+n+1);
	int pos = 1;
	while (pos < n)
	{
		isend = true;
		//判断所有怪兽全部退出或已经完成攻击 
		for (int i = 1; i <= n; i++)
		{
			if ((!(isdie[i])) && (!(fl[i])))
			{
				//cout << "Hello" << endl;
				isend = false;
				continue;
			}
			//cout << "hello" << endl;
		}
		//cout << "hello" << endl; 
		if (isend)
		{
			break;
		}
		for (int i = pos+1; i <= n; i++)
		{
			if (r[i] > r[pos] && !fl[i])
			{
				isdie[pos] = true;
				fl[i] = true;
				ans--;
				//cout << ans;
				break;
			}
		}
		//cout << ans << endl;
		pos++;
	}
	cout << ans << endl;
	return 0;
}
