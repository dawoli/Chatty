#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int val,cnt;
}a[100005];
bool cmp(node x,node y)
{
	return x.val<y.val;
}
int f[100005];
int m;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(!f[x])
		{
			f[x]=++m;
			a[m].val=x,a[m].cnt++;
		}
		else
		{
			a[f[x]].cnt++;
		}
	}
	sort(a+1,a+m+1,cmp);
	int alive=a[1].cnt;
	for(int i=2;i<=m;i++)
	{
		int dead=min(a[i].cnt,alive);
		alive=max(0,alive-dead+a[i].cnt);
	}
	cout<<alive<<endl;
	return 0;
}
