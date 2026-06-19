#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int ans;
void dfs(int start,int end,int minl,int l)
/*
start:	开始位置下标 
end:	结束位置下标
minl:	长度非严格最小值
l:		当前的长度总和 
函数内主要的逻辑为:
	(1)l <= minl,即不符合要求
		搜索所有从当前开始位置以后到当前结束位置的可能性
		即为dfs(i,end,minl,l + a[i]);
	(2)l > minl,即符合要求
		也按照上述要求搜索
		同时,更新计数器,即为++ans;ans %= 998244353; 
*/ 
{
	if (l <= minl)	//即为不符合条件 
	{
		for (int i = start;i < end;++i)
		{
			cout << i + 1 << " " << end << " " << l << endl;
			dfs(i + 1,end,minl,l + a[i]);
		}
	}
	
	else			//即为符合条件 
	{
		cout << l << " " << minl << endl << endl; 
		++ans;
		ans %= 998244353;
		//符合条件以后也要进行搜索
		for (int i = start;i < end;++i)
		{
			cout << i + 1 << " " << end << " " << l << endl;
			dfs(i + 1,end,minl,l + a[i]); 
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	a = vector<int>(n,0);
	for (int i = 0;i < n;++i)
		cin >> a[i];
//	sort(a.begin(),a.end());
//	for (int i = 0;i < n;++i)
//		cout << a[i] << " ";
//	cout << endl;
	for (int i = 0;i < n;++i)
	{
		int minl = a[i] * 2;
		//取长度的非严格最小值(所有长度必须大于minl)
		//在所有<=a[i]的长度中搜索符合上述要求的长度
		dfs(0,i,minl,0);	 
	}
	cout << ans << endl;
	return 0;
}
