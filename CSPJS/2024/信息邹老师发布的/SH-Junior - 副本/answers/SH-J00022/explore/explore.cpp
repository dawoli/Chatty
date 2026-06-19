#include<bits/stdc++.h>
using namespace std;
int k[10004][10004],n,m,o,x,y,d,t;
int ds[4]={1,0,-1,0};
int df[4]={0,1,0,-1};
char a;
int cdm(int xx,int yy,int dd,int sum,int badn)
{

	if(badn==0)
	{
		sum+=(k[xx][yy]==0);
		return sum;
	}
	if(yy+ds[dd]>=m or xx+df[dd]>=n)
	{
		if(k[xx][yy]==0)
		{
			k[xx][yy]=2;
			sum++;	
		}

		return cdm(xx,yy,(dd+1)%4,sum,badn-1);
	}
	if(yy+ds[dd]<0 or xx+df[dd]<0)
	{
		if(k[xx][yy]==0)
		{
			k[xx][yy]=2;
			sum++;
		}

		return cdm(xx,yy,(dd+1)%4,sum,badn-1);
	} 
	if(k[xx+df[dd]][yy+ds[dd]]==1)
	{	
		if(k[xx][yy]==0)
		{
			k[xx][yy]=2;
			sum++;
		}

		return cdm(xx,yy,(dd+1)%4,sum,badn-1);
	}
	if(k[xx][yy]==2)
	{
		return cdm(xx+df[dd],yy+ds[dd],dd,sum,badn-1);	

	}
	if(k[xx][yy]==0)
	{
		sum++;
		k[xx][yy]=2;
		return cdm(xx+df[dd],yy+ds[dd],dd,sum,badn-1);		
	}

	}
int main()
{
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>m>>o;
		cin>>x>>y>>d;
		for(int j=0;j<n;j++)
		{
			for(int g=0;g<m;g++)
			{
				cin>>a;
				k[j][g]=(a=='x');
			}
		}
		cout<<cdm(x-1,y-1,d,0,o)<<endl;
	}
	return 0;
}
