#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iterator>
#include<utility>
#include<algorithm>
using namespace std;
const int max_n=100002;
vector<int> master_def,equa;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		master_def.push_back(a);
	}
	sort(master_def.begin(),master_def.end());
	vector<int>::iterator it=master_def.begin();
	int cnt=1,pre=*it;
	*it=cnt;
	for(it=master_def.begin()+1;it!=master_def.end();it++)
	{
		if(*it!=pre)
		{
			cnt++;
			pre=*it;
		}
		*it=cnt;
	}
	pair<vector<int>::iterator,vector<int>::iterator> begin_end=equal_range(master_def.begin(),master_def.end(),1);
	pre=distance(begin_end.first,begin_end.second);
	int cur;
	for(int i=2;i<=cnt;i++)
	{
		begin_end=equal_range(master_def.begin(),master_def.end(),i);
		cur=distance(begin_end.first,begin_end.second);
		if(cur>pre)
		{
			pre=cur;
			cur=0;
		}
	}
	printf("%d\n",pre);
	return 0;
}
