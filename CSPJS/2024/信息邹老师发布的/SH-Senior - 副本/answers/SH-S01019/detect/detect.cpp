#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v1,d[100100],v[100100],a[100100],p[100100],b[1000100],c[1000100],sum,num;
struct det{
	int s,t;
}de[100100];
bool cmp(det a,det b)
{
	if(a.t!=b.t)
		return a.t<b.t;
	return a.s<b.s;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int t1=1;t1<=t;t1++)
	{
		memset(de,(0,0),sizeof(de));
		sum=0;
		num=0;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		scanf("%d%d%d%d",&n,&m,&l,&v1);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&p[i]);
		p[m+1]=l+1;
		p[0]=-1;
		for(int i=1;i<=m;i++)
		{
			for(int j=p[i];j<p[i+1];j++)
				b[j]=i;
			for(int j=p[i-1]+1;j<=p[i];j++)
				c[j]=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(d[i]<=p[m]&&v[i]>v1)
				{
					sum++;
					de[sum].s=c[d[i]];
					de[sum].t=m;
				}
			}
			else if(a[i]>0)
			{
				if(d[i]<=p[m])
				{
					if(v[i]>v1)
					{
						sum++;
						de[sum].s=c[d[i]];
						de[sum].t=m;
					}
					else
					{
						int p1;
						if((v1*v1-v[i]*v[i])%(2*a[i])==0)
							p1=(v1*v1-v[i]*v[i])/(2*a[i])+d[i]+1;
						else
							p1=(int)((v1*v1-v[i]*v[i])/(2*a[i]))+d[i]+1;
						if(p1<=p[m])
						{
							sum++;
							de[sum].s=c[p1];
							de[sum].t=m;
						}
					}
				}
			}
			else
			{
				if(v[i]>v1&&d[i]<=p[m])
				{
					int ss=c[d[i]];
					int tt; 
					if((v1*v1-v[i]*v[i])%(2*a[i])==0)
						tt=(v1*v1-v[i]*v[i])/(2*a[i])-1+d[i];
					else
						tt=(int)((v1*v1-v[i]*v[i])/(2*a[i]))+d[i];
					if(tt>=l)
						tt=l;
					if(tt>=p[ss])
					{
						sum++;
						de[sum].s=ss;
						de[sum].t=b[tt];
					}
				}
			}
		}
		sort(de+1,de+sum+1,cmp);
		for(int i=1;i<=sum;)
		{
			num++;
			int de1=de[i].t;
			while(de[i].s<=de1)
				i++;
		}
		cout<<sum<<" "<<m-num<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
