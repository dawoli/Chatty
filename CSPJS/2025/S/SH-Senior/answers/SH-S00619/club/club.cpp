#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][6],f[100001],gm[4][60000],m[4],minx;
char l[4];
int find_min(int x)//第x组中移除后满意度差最小的人的序号 
{
	int minn=1000000,r;
	for(int k=1;k<=m[x];k++)
	{
		if(a[gm[x][k]][x]-a[gm[x][k]][a[gm[x][k]][4]]<minn)
		{
			minn=a[gm[x][k]][x]-a[gm[x][k]][a[gm[x][k]][4]];
			r=k;
		}
	}
	return r;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	l[1]='A';l[2]='B';l[3]='C';
	for(int z=1;z<=t;z++)
	{
		cin>>n;
		m[1]=1;m[2]=1;m[3]=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				a[i][0]=1;
				if(a[i][2]>=a[i][3])
				{
					a[i][4]=2;
				}
				else
				{
					a[i][4]=3;
				}
				continue;
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				a[i][0]=2;
				if(a[i][1]>=a[i][3])
				{
					a[i][4]=1;
				}
				else
				{
					a[i][4]=3;
				}
				continue;
			}
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])
			{
				a[i][0]=3;
				if(a[i][1]>=a[i][2])
				{
					a[i][4]=1;
				}
				else
				{
					a[i][4]=2;
				}
				continue;
			}
		}
		for(int i=1;i<=n;i++)
		{
			f[i]=f[i-1]+a[i][a[i][0]];
			gm[a[i][0]][m[a[i][0]]]=i;
			m[a[i][0]]++;
			if(m[a[i][0]]-1>n/2)
			{
				m[a[i][0]]--;
				minx=find_min(a[i][0]);//cout<<'*'<<minx<<endl;
				int d=gm[a[i][0]][minx];//被移除的序号 
				f[i]-=a[d][a[i][0]];//cout<<'-'<<a[d][a[i][0]];
				f[i]+=a[d][a[d][4]];//cout<<'+'<<a[d][a[d][4]]<<'=';
				gm[a[d][4]][m[a[d][4]]]=gm[a[i][0]][minx];
				gm[a[i][0]][minx]=gm[a[i][0]][m[a[i][0]]];
				gm[a[i][0]][m[a[i][0]]]=0;
				m[a[d][4]]++;
			}
			/*
			cout<<f[i]<<' '<<m[1]-1<<' '<<m[2]-1<<' '<<m[3]-1<<endl;
			for(int i=1;i<=3;i++)
			{
				cout<<l[i];
				for(int j=1;gm[i][j];j++)
				{
					cout<<gm[i][j]<<' ';
				}
				cout<<endl;
			}
			*/
		}
		cout<<f[n]<<endl;
	}
	return 0;
}
