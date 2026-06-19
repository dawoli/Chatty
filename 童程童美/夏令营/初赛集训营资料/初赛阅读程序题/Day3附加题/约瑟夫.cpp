#include <bits/stdc++.h>
using namespace std;
bool vis[1005];
int main()
{
	int n, m, vn = 0, num = 0, i = 0;
	cin >> n >> m;
    while(vn < n)
	{
		if(vis[i] == false)
		{
			num++;
			if(num == m)
			{
				cout << i+1 << ' ';
				vis[i] = true;
				num = 0;
				vn++;
			}
		}
		i = (i+1)%n;
 	}
    return 0;
}
