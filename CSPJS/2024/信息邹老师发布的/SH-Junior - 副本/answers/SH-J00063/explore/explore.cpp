#include "bits/stdc++.h"
using namespace std;
char a[1001][1001];
int next_x,next_y,m,n;
bool map_1145()
{
	if(next_x<n&&next_y<m&&next_y>=0&&next_x>=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool st()
{
	if(a[next_x][next_y]!='x')
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int T,r_x,r_y,d,res=1,t;
	int temp=0;
	cin>>T;
	for(int j=0;j<T;j++)
	{
		cin>>n>>m>>t;
		cin>>r_x>>r_y>>d;
		r_x=r_x-1;
		r_y=r_y-1;
		for(int i=0;i<n;i++)
		{
			cin>>a[i][0];
//			printf("a[%d][0]:%c ",i,a[i][0]);
			for(int k=1;k<m;k++)
			{
				cin>>a[i][k];
//				printf("a[%d][%d]:%c ",i,k,a[i][k]);
			}
//			cout<<endl;
		}
		for(int i=0;i<t;i++)
		{
			if(d==0)
			{
				next_x=r_x;
				next_y=r_y+1;
			}
			else if(d==1)
			{
				next_x=r_x+1;
				next_y=r_y;
			}
			else if(d==2)
			{
				next_x=r_x;
				next_y=r_y-1;
			}
			else
			{
				next_x=r_x-1;
				next_y=r_y;
			}
			if(map_1145()&&st())
			{
				res++;
				r_y=next_y;
				r_x=next_x;
//				printf("x:%d   y:%d   d:%d\n",r_x,r_y,d);
			}
			else
			{
				while(map_1145()==false||st()==false)
				{
					d=(d+1)%4;
					if(d==0)
					{
						next_x=r_x;
						next_y=r_y+1;
					}
					else if(d==1)
					{
						next_x=r_x+1;
						next_y=r_y;
					}
					else if(d==2)
					{
						next_x=r_x;
						next_y=r_y-1;
					}
					else
					{
						next_x=r_x-1;
						next_y=r_y;
					}
					if(temp>3)
					{
						cout<<res;
						return 0;
					}
					temp++;
					if(i<t-temp+1==false)
					{
						cout<<res;
						return 0;
					}
				}
				res++;
				t=t-temp+1;
				r_y=next_y;
				r_x=next_x;
//				printf("x:%d   y:%d   d:%d\n",r_x,r_y,d);
			}
		}
	}
	cout<<res;
	return 0;
}
