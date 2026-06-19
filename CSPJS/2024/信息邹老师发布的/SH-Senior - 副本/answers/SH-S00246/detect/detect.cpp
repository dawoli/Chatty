#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int maxn=1000005;
int n, m, L, V; 
int v[maxn], a[maxn], p[maxn], d[maxn];
long double t[maxn];
//int ans[maxn]; // 差分数组,前缀和记录在ans[i]有多少人超速 
//int pre[maxn];
int p_pre[maxn]; // p的前缀和
int ans_detect, ans_del;
vector<pii> I; // 超速区间 
bool cmp(pii &a, pii&b) // 按照结束时间排序 
{
	return a.second < b.second;
}
bool check(int l, int r)
{
	for(int i=l;i<=r;i++)
	{
		if (p[i])
		{
			return 1;
		}
	}
	return 0;
}
void add(int l, int r)
{
//	ans[l]++;
//	ans[r+1]--;
	if (check(l, r))
	{
//		cout<<"checked"<<l<<' '<<r<<endl;
		ans_detect++;
		I.push_back(make_pair(l, r));
	}
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int ttt;
	cin>>ttt;
	while(ttt--)
	{
		ans_detect=0;
		cin>>n>>m>>L>>V;
//		memset(ans, 0, sizeof(ans));
		memset(p, 0, sizeof(p));
		I.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			int tmp;
			cin>>tmp;
			p[tmp]++;
//			for(int j=p[i];j<=L;j++)
//			{
//				p_pre[j]++;
//			}
		}
		for(int i=1;i<=n;i++)
		{
			
			if (a[i] != 0)
			{
				long long int_part = (pow(V, 2) - pow(v[i], 2)) / (2 * a[i]);
				bool not_divided = ((abs((long long)(pow(V, 2) - pow(v[i], 2)))) % abs((2 * a[i]))) > 0;
				long long t_ceil = d[i] + int_part + not_divided;
				long long t_floor = d[i] + int_part;
//				t[i] = d[i] + (pow(V, 2) - pow(v[i], 2)) / (2 * a[i]);
				if (t_ceil>L)t_ceil = L;
				if (t_ceil<0) t_ceil=0;
				if (t_floor>L)t_floor = L;
				if (t_floor<0) t_floor=0;
				if (a[i] > 0)
				{
					add(t_ceil, L);
				}
				else
				{
					add(d[i], t_floor);
				}
			}
			else if (v[i] > V)
			{
				add(d[i], L);
			}
		} 
//		pre[0]=ans[0];
//		for(int i=1;i<=L;i++)
//		{
//			pre[i] = pre[i-1] + ans[i];
//		}
//		for(int i=1;i<=L;i++)
//		{
//			cout<<pre[i]<<' ';
//		}
		
		// 区间覆盖,不相交的区间数量 
		
		sort(I.begin(), I.end(), cmp);
		int ans_del=m; // 这玩意是m,不是n,为什么我要搞那么久?????? 
		int lt=-1; // 上一次区间的最大值 
		for(auto &i:I)
		{
//			cout<<"pair:"<<i.first<<' '<<i.second<<endl;
			if (i.first > lt)
			{
				for(int j=i.second;j>=i.first;j--)
				{
					if (p[j])
					{
						lt=j;
//						cout<<"newlt:"<<lt<<endl;
						ans_del--;
						break;
					}
					
				}
			}
		}
		cout<<ans_detect<<' '<<ans_del<<endl;
	}
	return 0;
}

