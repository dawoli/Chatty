#include <bits/stdc++.h>
using namespace std;

struct node
{
	int d, v, a;
} car[3005];

struct node2
{
	int id, num;
} cnt[3005];

bool box[3005], use[3005][3005];
int T, n, m, L, V, cnt_p, cnt_c, p[3005];

bool cmp(node2 a, node2 b)
{
	return a.num > b.num;
}

void find_p()
{
	int cal = cnt_c;// 超速汽车个数 
	sort (cnt + 1, cnt + m + 1, cmp); // 从大到小排一遍 
	while (cal > 0)// 一直到都能检测出来 
	{
		int id = cnt[1].id;// 目前检测汽车最多的检测器编号 
		cal -= cnt[1].num;// 剃掉 
		cnt[1].num = 0; cnt_p++;// 归零，必须要留的数量 + 1 
		for (int i = 1; i <= n; i++)
			if (use[id][i])	box[i] = false;//i 号的车被 id 号的检测器发现，归零 
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (!box[j])	use[cnt[i].id][j] = false;//剔除多余的 
				// 如果 j 号车被剔除掉，标记，数量 -1
		for (int i = 1; i <= m; i++)
		{
			cnt[i].num = 0;
			for (int j = 1; j <= n; j++) 
				if (use[cnt[i].id][j])	cnt[i].num++;
		}// 重新计算 
		memset(use[id], false, sizeof use[id]);// 全部归零 
		sort (cnt + 1, cnt + m + 1, cmp);
	}
}

bool check(int id)
{
	bool flag = true;
	int d = car[id].d, v = car[id].v, a = car[id].a, last = 0;
	for (int i = 1; i <= m; i++)
	{
		if (p[i] < d)	continue;// 没有经过 
		double speed = sqrt(1.0 * v * v + 2.0 * a * (p[i] - d));// 目前速度 
		if (speed <= 0)	break;// 已经离开 
		if (speed > V)// 超速 
		{
			cnt[i].num++; // i 号检测器的检测个数 + 1 
			use[i][id] = true;//id 号的车被 i 号的检测器发现 
			flag = false;// 已超速 
		}
	}
	return flag;
}

void solve()
{
	cin >> n >> m >> L >> V;// 车辆个数、检测器个数、桥梁长度、最高速度 
	for (int i = 1; i <= n; i++)
		cin >> car[i].d >> car[i].v >> car[i].a;
	// 初始位置、初始速度、加速度 
	for (int i = 1; i <= m; i++)
		cin >> p[i];// 检测器位置 
	for (int i = 1; i <= n; i++)
		if (!check(i))	cnt_c++, box[i] = true;// 判断是否超速 
	cout << cnt_c << ' ';
	for (int i = 1; i <= m; i++)	cnt[i].id = i;
	find_p();// 计算要开启的个数 
	cout << m - cnt_p << endl; 
	cnt_c = cnt_p = 0;
	memset(use, false, sizeof use);
	// 初始化 
}

int main()
{
	freopen ("detect.in", "r", stdin);
	freopen ("detect.out", "w", stdout);
	cin >> T;
	while (T--)	solve();// T 组数据 
	return 0;
}

// 16:25 : 通过前两个样例，复杂度 O(nm)+， 最坏 O(n ^ 2 m) -> 20pts 
