#include<bits/stdc++.h>
using namespace std;

int n,m;
priority_queue <int> pq;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int inn;
	int sc=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&inn);
			if(i==1&&j==1)
			{
				sc=inn;
			}
			pq.push(inn);
		}
	}
	int num=0;
	while(!pq.empty())
	{
		num++;
		if(pq.top()==sc)
		{
			break;
		}
		pq.pop();
	}
	int ansn,ansm;
	ansm=(num-1)/n+1;
	if(ansm%2)
	{
		ansn=(num-1)%n+1;
	}
	else
	{
		ansn=n-(num-(ansm-1)*n)+1;
	}
	printf("%d %d",ansm,ansn);
	
	return 0;
}
