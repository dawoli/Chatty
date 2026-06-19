#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
	
	int T;
	long long n,m,L,V;	
	int d[100002],v[100002],a[100002],p[100002];
	bool f1,f2,f3;
	int count;
	long long speed;
	bool c[21][21],dd[21];
	int id,max,tmp;
	
	int ii,i,j;
	
	cin>>T;
	for(ii=0;ii<T;ii++)
	{
		f1=1;
		f2=1;
		cin>>n>>m>>L>>V;
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&d[i],&v[i],&a[i]);
			if(a[i]!=0 && f1) f1=0;
			if(a[i]<=0 && f2) f2=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&p[i]);
		}
		
		if(f1)
		{
			count=0;
			for(i=0;i<n;i++)
			{
				if(v[i]>V && d[i]<=p[m-1])
					count++;
			}
			cout<<count<<" ";
			if(count==0) cout<<m;
			else cout<<m-1;
			cout<<endl;
		}
		else if(f2)
		{
			count=0;
			for(i=0;i<n;i++)
			{
				if(d[i]<=p[m-1] && ((long long)v[i])*v[i]+2*a[i]*(p[m-1]-d[i])>V*V)
					count++;
			}
			cout<<count<<" ";
			if(count==0) cout<<m;
			else cout<<m-1;
			cout<<endl;
		}
		else if(n<=20 && m<=20)
		{
			count=0;
			memset(c,0,sizeof(c));
			memset(dd,0,sizeof(dd));
			for(i=0;i<n;i++)
			{
				f3=0;
				for(j=0;j<m;j++)
				{
					speed=((long long)v[i])*v[i]+2*a[i]*(p[j]-d[i]);
					if(d[i]<=p[j] && speed>V*V)
					{
						f3=1;
						c[i][j]=1;
					}
				}
				if(f3) count++;
			}
			cout<<count<<" ";
			
			count=0;
			while(1)
			{
				max=0;
				id=-1;
				for(j=0;j<m;j++)
				{
					tmp=0;
					for(i=0;i<n;i++)
						{
						if(c[i][j])
							tmp++;
					}
					if(tmp>max)
					{
						max=tmp;
						id=j;
					}
				}
				if(max==0) break;
				for(i=0;i<n;i++)
					if(c[i][id])
						for(j=0;j<m;j++)
							c[i][j]=0;
				count++;
			}
			cout<<m-count<<endl;
		}
		else
		{
			cout<<":P"<<endl;
		}
	}	
	
	return 0;
}
