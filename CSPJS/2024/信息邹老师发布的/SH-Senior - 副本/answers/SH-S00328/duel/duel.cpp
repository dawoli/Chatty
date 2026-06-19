#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+5;
int n;
multiset<int> living_monster;

signed main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		//输入 
		int tmp;
		cin>>tmp;
		living_monster.insert(tmp);
	}
	for(auto this_monster:living_monster)
	{
		//找第一个严格不如当前怪兽的 
		auto iter=living_monster.lower_bound(this_monster);
		if(iter==living_monster.begin())
		{
			continue;
		}
		iter--;
		//如果找不到->continue
		int killed_monster=*iter;
		//否则击败找到的怪兽 
		living_monster.erase(living_monster.find(killed_monster));
	}
	cout<<living_monster.size();
	return 0;
}
