#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];
map<int, int> r_cnt;// 记录多少个这个r的没有被用过了
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		r_cnt[a[i]] ++;
	}
	sort(a + 1, a + n + 1);
	int ans=n;
	for(int i=1;i<=n;i++)
	{
//		pair<int, int> ind = r_cnt.upper_bound(a[i]);
		if (r_cnt.upper_bound(a[i]) != r_cnt.end())
		{
			ans--;
			pair<int, int> pii = *r_cnt.upper_bound(a[i]); // 即将被减少的值,这个值剩余的数量 
			r_cnt[pii.first]--;
			if (r_cnt[pii.first] == 0) r_cnt.erase(pii.first);
		}
//		cout<<ind.first<<' '<<ind.second<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
