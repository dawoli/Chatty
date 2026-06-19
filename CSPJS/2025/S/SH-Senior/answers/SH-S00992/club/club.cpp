#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
考虑部分分：
1 ~ 4 : 暴力枚举 
5 ~ 11 : dp[id][i][j][k] : 第 id 个人，1 号部门 i 个， 2 号部门 j 个，3 号部门 k 个 (第一纬压掉)
12 : 从大到小排序，选前 n / 2 个
13 ~ 14 : dp[id][i] : 第 id 个人，1 号部门 i 个，2 号部门 id - i 个 (第一纬压掉)
--------------------------------------
75 pts 没问题，考虑下正解：
什么时候不用考虑 n / 2 的限制？就是每个人按照最优选也是 OK 的。
所以接下来只用考虑超过 n / 2 限制的。
在刚刚的预处理里面，我们知道了哪个部门会出现 n / 2 个人（不会有超过 1 个部门） 
那么不妨令 dp[id][i] : 第 id 个人。最热门的部门有 i 个人，获得的最大值。id 压纬压掉即可。
大概是 : 
for (int id : 1 -> n)
	for (int j : 1 -> id)
好像还是要超时？
对 dp 很不友好啊……
----------------------------------------
还有一种可能，先按预处理的分配。然后试着把最热门部门里面交换减少价值最低的人，
和其他部门里面去热门部门增加最多的人交换？
可以试试看，前面的 dp 作为前 50% 的保底。 
*/ 

const int N = 1e5 + 5;

struct Node
{
	int d[5];
} a[N];

priority_queue <int> q; // 换到别的地方能获得的最大收益 
int T, n, ans, mxid; 


void clear()
{
	ans = mxid = 0;
	while (!q.empty())	q.pop();
}

int prep()
{
	int res = 0, siz1 = 0, siz2 = 0, siz3 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i].d[1] >= a[i].d[2] && a[i].d[1] >= a[i].d[3])
		{
			res += a[i].d[1];
			siz1++;
		}
		else if (a[i].d[2] >= a[i].d[1] && a[i].d[2] >= a[i].d[3])
		{
			res += a[i].d[2];
			siz2++;
		}
		else if (a[i].d[3] >= a[i].d[1] && a[i].d[3] >= a[i].d[2])
		{
			res += a[i].d[3];
			siz3++;
		}
	}
	if (siz1 > n / 2)
	{
		mxid = 1;
		return -1;
	}
	if (siz2 > n / 2)
	{
		mxid = 2;
		return -1;
	}
	if (siz3 > n / 2)
	{
		mxid = 3;
		return -1;
	}
	return res;
}

void solve()
{
	clear();
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].d[1] >> a[i].d[2] >> a[i].d[3];
	if (prep() != -1)	
	{
		cout << prep() << "\n";
		return; 
	}
	for (int i = 1; i <= n; i++)
		swap(a[i].d[1], a[i].d[mxid]);
	for (int i = 1; i <= n; i++)
	{
		if (a[i].d[1] <= a[i].d[2] || a[i].d[1] <= a[i].d[3])
			ans += max(a[i].d[2], a[i].d[3]);
		else
		{
			ans += a[i].d[1];
			q.push(max(a[i].d[2] - a[i].d[1], a[i].d[3] - a[i].d[1]));
		}
	}
	while (q.size() > n / 2)
	{
		int now = q.top(); q.pop();
		ans += now;
	}
	cout << ans << "\n";
}

signed main()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout); 
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)	solve();
	return 0;
}

// 15 : 32 通过所有大样例，似乎想复杂了，就是把能放的先放，然后把损失尽量小的移出。这个打字也太垃圾了。记得检查。 
