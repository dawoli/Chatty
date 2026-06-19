#include<bits/stdc++.h>
using namespace std;

struct node
{
	int num;
	int id;
}a[105];


bool cmp(node a,node b)
{
	return a.num>b.num;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>  n >> m;
	for(int i = 1;i<=n*m;i++)
	{
		cin >> a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int cnt = 1;
	for(int j = 1;j<=m;)
	{
		for(int i = 1;i<=n;i++)
		{
			if(a[cnt].id==1)
			{
				cout << j <<" "<<i;
				return 0;
			}
			cnt++;
		}
		j++;
		for(int i = n;i>0;i--)
		{
			if(a[cnt].id==1)
			{
				cout << j <<" "<<i;
				return 0;
			}
			cnt++;
		}
		j++;
	}
	
	return 0;
}
