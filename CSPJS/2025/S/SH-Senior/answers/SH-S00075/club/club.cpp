#include <bits/stdc++.h>
using namespace std;

struct node
{
	int d[4],mi;
}a[100005];

bool cmp(node a,node b)
{
	return a.mi>b.mi;
}

int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		
		int n;
		cin >> n;
		if(n==2)
		{
			int e[3][4];
			for(int i=1;i<=2;i++)
			{
				for(int j=1;j<=3;j++)
				{
					cin >> e[i][j];
				}
			}
			int maxn=0;
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i!=j) maxn=max(e[1][i]+e[2][j],maxn);
				}
			}
			cout << maxn << endl;
		}
		else if(n==4)
		{
			int e[5][4];
			for(int i=1;i<=4;i++)
			{
				for(int j=1;j<=3;j++)
				{
					cin >> e[i][j];
				}
			}
			int maxn=0;
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					for(int p=1;p<=3;p++)
					{
						for(int q=1;q<=3;q++)
						{
							int op[4]={0,0,0,0};
							op[i]++;op[j]++;op[p]++;op[q]++;
							/*if(!((i==j==p)||(i==j==q)||(i==p==q)||(j==p==q)))*/if(op[1]<3&&op[2]<3&&op[3]<3) maxn=max(e[1][i]+e[2][j]+e[3][p]+e[4][q],maxn);
						}
					}

				}
			}
			cout << maxn << endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				cin >> a[i].d[1] >> a[i].d[2] >> a[i].d[3];
				a[i].mi=a[i].d[1]-a[i].d[2];
			}
			sort(a+1,a+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++)
			{
				sum+=a[i].d[1];
			}
			for(int i=n/2+1;i<=n;i++)
			{
				sum+=a[i].d[2];
			}
			cout << sum << endl;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
