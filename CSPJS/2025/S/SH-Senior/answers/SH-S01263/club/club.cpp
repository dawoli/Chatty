#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int t, n;
int a[MAXN][5] = {}; // 记录满意度 
int p[MAXN][5] = {}; // 记录满意度对应的部门 
int tmp[5] = {}; // 暂存用sort
int people[5] = {}; // 储存三个部门的人数 
int ans;
bool flag = false;


bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	for (int k = 1; k <= t; k++)
	{
		cin >> n;
		people[1] = 0, people[2] = 0, people[3] = 0;
		ans = 0;
		int MAX_PEOPLE_PER_CLUB = n / 2;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			tmp[0] = a[i][1];
			tmp[1] = a[i][2];
			tmp[2] = a[i][3];
			p[i][1] = p[i][2] = p[i][3] = 0;
			// 给a[i][1], a[i][2], a[i][3]排序
			sort(tmp, tmp + 3, cmp);
			for (int m = 1; m <= 3; m++)
			{
				for (int n = 0; n <= 2; n++)
				{
					if (a[i][m] == tmp[n])
					{
						if (p[i][n + 1] == 0)
						{
							p[i][n + 1] = m;
							break;
						}
					}
				}
			}
			// tmp[2]最大 tmp[0]最小 
			// p[i][x] = y 表示第i人排名第x大的满意度为部门y 
			// cout << a[i][1] << " " << a[i][2] << " " << a[i][3] << endl;
			// cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;
			// cout << p[i][1] << " " << p[i][2] << " " << p[i][3] << endl;
		}
		
		for (int i = 1; i <= n; i++)
		{
			// 选择第i人最大的部门 p[i][1]
			// 先判断该部门是否超过最大人数
			if (people[p[i][1]] + 1 <= MAX_PEOPLE_PER_CLUB)
			{
				// 不超过则人数+1，ans + 该部门满意度
				people[p[i][1]]++;
				ans += a[i][p[i][1]];	
			}
			// 超过则找到第二的部门
			else if (people[p[i][2]] + 1 <= MAX_PEOPLE_PER_CLUB)
			{
				people[p[i][2]]++;
				ans += a[i][p[i][2]];
			}
			else
			{
				people[p[i][3]]++;
				ans += a[i][p[i][3]];
			}
		}
		cout << ans << endl;
	}
	
	
	return 0;
} 
