#include<bits/stdc++.h>
using namespace std;
const int N=1000007;
int n;
struct Node
{
	int x[5];
	int mx,m2;
}a[N];
bool cmp(Node a,Node b)
{
	return (a.x[a.mx]-a.x[a.m2])>(b.x[b.mx]-b.x[b.m2]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a)); 
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
			if(a[i].x[1]>a[i].x[2])
			{
				if(a[i].x[1]>a[i].x[3])
				{
					a[i].mx=1;
					if(a[i].x[2]>a[i].x[3])a[i].m2=2;
					else a[i].m2=3;
				}
				else
				{
					a[i].mx=3;
					a[i].m2=1;
				}
			}
			else
			{
				if(a[i].x[2]>a[i].x[3])
				{
					a[i].mx=2;
					if(a[i].x[1]>a[i].x[3])a[i].m2=1;
					else a[i].m2=3;
				}
				else
				{
					a[i].mx=3;
					a[i].m2=2;
				}
			}
		
		}
		sort(a+1,a+1+n,cmp);
		int ans=0;
		int c[5]={};
		for(int i=1;i<=n;i++)
		{
			if(a[i].mx==1)
			{
				if(c[1]+1<=n/2)
				{
					ans+=a[i].x[1];
					c[1]++;
				}
				else
				{
					ans+=a[i].x[a[i].m2];
					c[a[i].m2]++;
				}
			}
			else if(a[i].mx==2)
			{
				if(c[2]+1<=n/2)
				{
					ans+=a[i].x[2];
					c[2]++;
				}
				else
				{
					ans+=a[i].x[a[i].m2];
					c[a[i].m2]++;
				}
			}
			else if(a[i].mx==3)
			{
				if(c[3]+1<=n/2)
				{
					ans+=a[i].x[3];
					c[3]++;
				}
				else
				{
					ans+=a[i].x[a[i].m2];
					c[a[i].m2]++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
