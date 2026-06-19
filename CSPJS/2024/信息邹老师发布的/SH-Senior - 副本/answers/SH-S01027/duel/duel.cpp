//今年题目 神如经 逆如天 
#include <bits/stdc++.h>
using namespace std;
int r[100010];
int rt[100010];
queue <int>q;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);	
	int n,maxn = 0,minn = 1e5+10;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&r[i]);
		rt[r[i]] ++;
		maxn = max(maxn,r[i]);
		minn = min(minn,r[i]);
	}
	for(int i = minn;i <= maxn;i++)
	{
		if(rt[i] != 0)
		{
			while(rt[i]--)
			{
				if(i > q.front())
				{
					q.pop();
					q.push(i);
				}
				else
				{
					q.push(i);
				}
			}
		}
	}
	printf("%d",q.size());
	return 0;
}
