#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int f[N][N];
struct node
{
	int index;
	int grade;	
}a[N];
int cmp(node a,node b)
{
	return a.grade>b.grade;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].grade;
		a[i].index=i;
	}
	int cnt=2;
	sort(a+1,a+n*m+1,cmp);
	f[1][1]=a[1].index;
	int r=1;
	for(int i=1,j=1;j<=n;)
	{
		if(i>=m&&r==0)
		{
			r=1;
			j++;
			f[i][j]=a[cnt].index;
			cnt++;
		}
		else if(i<=1&&r==0)
		{
			r=1;
			j++;
			f[i][j]=a[cnt].index;
			cnt++;
		}
		else if(j%2==1)
		{
			r=0;
			i++;
			f[i][j]=a[cnt].index;
			cnt++;
		}
		else if(j%2==0)
		{
			r=0;
			i--;
			f[i][j]=a[cnt].index;
			cnt++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			//cout<<f[i][j]<<" ";
			if(f[i][j]==1)
			{
				cout<<j<<" "<<i;	
				return 0;
			}
		}
	}
}
