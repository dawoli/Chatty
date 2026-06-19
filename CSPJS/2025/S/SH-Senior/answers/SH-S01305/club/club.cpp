#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int cnt1[4], cnt, n;

int ans = 0, maxn[N];
struct S
{
	int num, val; 
} a1[N], a2[N], a3[N], sec[N], dis[N], minn[N];
bool used[N];
bool cmp(S a, S b)
{
	if (a.val == b.val) return a.num < b.num;
	return a.val > b.val;
}
//void check()
//{
//	int numb[4];
//	for (int i = 1; i <= n; i++)
//	{
//		if (used[a1[i].num] == false) numb[1]++;
//		if (used[a2[i].num] == false) numb[2]++;
//		if (used[a3[i].num] == false) numb[3]++;
//	}
//	numb[1] = n, numb[2] = n, numb[3] = n;
//	while (numb[1] > cnt || numb[2] > cnt || numb[3] > cnt)
//	{
//		int i = 1;
//		if (numb[1] > cnt)
//		{
//			used[a1[n - i + 1].num] = true;
//			numb[1]--;
//		}
//		if (numb[2] > cnt) 
//		{
//			used[a2[n - i + 1].num] = true;
//			numb[2]--;
//		}
///		if (numb[3] > cnt) 
//		{
//			used[a3[n - i + 1].num] = true;
//			numb[3]--;
//		}
//		i++;
//	}
//}

int main()
{
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		ans = 0;
		memset(cnt1, 0, sizeof(cnt1));
		memset(used, 0, sizeof(used));
		memset(maxn, 0, sizeof(maxn));
		memset(minn, 0, sizeof(minn));
		memset(sec, 0, sizeof(sec));
		memset(dis, 0, sizeof(dis));		
		
//		int a1[N], a2[N], a3[N];
		
		
		
		cin >> n;  //新成员数量 
		cnt = n / 2;  //各部门人数 <= cnt 
		
		for (int i = 1; i <= n; i++)
		{
			cin >> a1[i].val >> a2[i].val >> a3[i].val; //每个人的三个满意度 
			a1[i].num = i; a2[i].num = i; a3[i].num = i; dis[i].num = i; sec[i].num = i;
			used[i] = false;
			maxn[i] = max(a1[i].val, a2[i].val);
			maxn[i] = max(maxn[i], a3[i].val); // -> 个人最大的满意度 
			
			minn[i].val = min(a1[i].val, a2[i].val);
			minn[i].val = min(minn[i].val, a3[i].val); // -> 个人最小的满意度 
			
			if (a1[i].val != maxn[i] && a1[i].val != minn[i].val) sec[i].val = a1[i].val;
			if (a2[i].val != maxn[i] && a2[i].val != minn[i].val) sec[i].val = a2[i].val;
			if (a3[i].val != maxn[i] && a3[i].val != minn[i].val) sec[i].val = a3[i].val; // ->2nd
			
			dis[i].val = maxn[i] - sec[i].val;
		}
		sort(a1 + 1, a1 + n + 1, cmp);
		sort(a2 + 1, a2 + n + 1, cmp);
		sort(a3 + 1, a3 + n + 1, cmp);
		sort(minn + 1, minn + n + 1, cmp);
		sort(dis + 1, dis + n + 1, cmp);
		
//		check();
		int ans1;
//		used[a1[1].num] = true;
//		cnt1[1]++;
		for (int i = 1; i <= n; i++) 
		{
			
			if (cnt1[1] >= cnt) 
			{
				for (int j = i; j <= n; j++) used[a1[i].num] = true;
			}
			if (cnt1[2] >= cnt) 
			{
				for (int j = i; j <= n; j++) used[a2[i].num] = true;
			}
			if (cnt1[3] >= cnt) 
			{
				for (int j = i; j <= n; j++) used[a3[i].num] = true;
			}
			
			
			if (used[a1[i].num] == false && a1[i].val == maxn[a1[i].num]) 
			{
//				if (dis[a1[i].num].val < dis[a1[i + 1].num].val) continue;
//				else
//				{
				
				
				ans1 += a1[i].val;
				used[a1[i].num] == true;
				cnt1[1]++;
//				}
			}
			if (used[a2[i].num] == false && a2[i].val == maxn[a2[i].num] ) 
			{
//				if (dis[a2[i].num].val < dis[a2[i + 1].num].val) continue;
//				else
//				{
				
				ans1 += a2[i].val;
				used[a2[i].num] == true;
				cnt1[2]++;
//				}
			}
			if (used[a3[i].num] == false && a3[i].val == maxn[a3[i].num]) 
			{
//				if (dis[a3[i].num].val < dis[a3[i + 1].num].val) continue;
//				else 
//				{
				
				ans1 += a3[i].val;
				used[a3[i].num] == true;
				cnt1[3]++;
//				}
			}
		}
		ans = max(ans, ans1);
		
		cnt = n / 2;
		memset(cnt1, 0, sizeof(cnt1));
		memset(used, 0, sizeof(used));
		
		int ans2 = a2[1].val;
		used[a2[1].num] = true;
		cnt1[2] = 1;
		cnt1[1] = 0;
		used[a1[2].num] = false;
//		cout << "ttt" << used[a1[2].num] << endl;
		for (int i = 1; i <= n; i++)
		{
			if (cnt1[1] >= cnt) 
			{
				for (int j = i; j <= n; j++) used[a1[i].num] = true;
			}
			if (cnt1[2] >= cnt) 
			{
				for (int j = i; j <= n; j++) used[a2[i].num] = true;
			}
			if (cnt1[3] >= cnt) 
			{
				for (int j = i; j <= n; j++) used[a3[i].num] = true;
			}
			
			
			if (used[a1[i].num] == false && a1[i].val == maxn[a1[i].num]) 
			{		
				ans2 += a1[i].val;
				used[a1[i].num] == true;
				cnt1[1]++;
			}
			if (used[a2[i].num] == false && a2[i].val == maxn[a2[i].num] ) 
			{			
				ans2 += a2[i].val;
				used[a2[i].num] == true;
				cnt1[2]++;
			}
			if (used[a3[i].num] == false && a3[i].val == maxn[a3[i].num]) 
			{	
				ans2 += a3[i].val;
				used[a3[i].num] == true;
				cnt1[3]++;
			}
		}
		ans = max(ans1, ans2);
//		cout << "ttt" << used[a1[2].num] << endl;
//		cout << "a1[2].val" << a1[2].val << endl;
		
		memset(cnt1, 0, sizeof(cnt1));
		memset(used, 0, sizeof(used));
		int ans3 = a3[1].val;
		used[a3[1].num] = true;
		cnt1[3]++;
		for (int i = 2; i <= n; i++)
		{
			if (cnt1[1] >= cnt) 
			{
				for (int j = i; j <= n; j++) used[a1[i].num] = true;
			}
			if (cnt1[2] >= cnt) 
			{
				for (int j = i; j <= n; j++) used[a2[i].num] = true;
			}
			if (cnt1[3] >= cnt) 
			{
				for (int j = i; j <= n; j++) used[a3[i].num] = true;
			}
			
			
			if (used[a1[i].num] == false && a1[i].val == maxn[a1[i].num]) 
			{
//				if (dis[a1[i].num].val < dis[a1[i + 1].num].val) continue;
//				else
//				{
				
				
				ans3 += a1[i].val;
				used[a1[i].num] == true;
				cnt1[1]++;
//				}
			}
			if (used[a2[i].num] == false && a2[i].val == maxn[a2[i].num] ) 
			{
//				if (dis[a2[i].num].val < dis[a2[i + 1].num].val) continue;
//				else
//				{
				
				ans3 += a2[i].val;
				used[a2[i].num] == true;
				cnt1[2]++;
//				}
			}
			if (used[a3[i].num] == false && a3[i].val == maxn[a3[i].num]) 
			{
//				if (dis[a3[i].num].val < dis[a3[i + 1].num].val) continue;
//				else 
//				{
				
				ans3 += a3[i].val;
				used[a3[i].num] == true;
				cnt1[3]++;
			}
		}
		ans = max(ans1, ans2);
		ans = max(ans, ans3);
		
//		cout << "ans1:" << ans1 << endl;
//		cout << "ans2:" << ans2 << endl;
		cout << ans << endl;
	}
		
	
	return 0;
}
