#include<iostream>
using namespace std;
struct imsort
{
	int value;
	int where;
};
imsort b[100001];
imsort a[100001];
void msort(int l,int r)
{
	if(l==r)return ;
	int mid=(l+r)>>1;
	msort(l,mid);
	msort(mid+1,r);
	int i=l,j=mid+1;
	int top=l-1;
	while(i<=mid&&j<=r)
	{
		if(b[i].value<=b[j].value)a[++top]=b[i++];
		else b[++top]=a[j++];
	}
	while(i<=mid)b[++top]=a[i++];
	while(j<=r)b[++top]=a[j++];
	for(int m=l;m<=r;m++)b[m]=a[m];
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m,l,vv;
		cin>>n>>m>>l>>vv;
		if(i!=1)
		{
			for(int j=1;j<=n;j++)
			{
				b[j].value=0;
				b[j].where=0;
			}
		}
		int d[100001]={0};
		int v[100001]={0};
		int a[100001]={0};
		int q[100001]={0}; 
		for(int j=1;j<=n;j++)
		{
			cin>>d[j]>>v[j]>>a[j];
		}
		for(int j=1;j<=m;j++)
		{
			cin>>q[j];
		}
		int beginn[100001]={0};
		int endd[100001]={0};
		int result1=0; 
		for(int i=1;i<=n;i++)
		{
			beginn[i]=-0x7ffffff;
			endd[i]=-0x7ffffff;
			if(v[i]<=vv&&a[i]<=0)continue;
			else
			{
				if(v[i]>vv&&a[i]>=0)
				{
					for(int j=1;j<=m;j++)
					{
						if(q[j]>=d[i])
						{
							beginn[i]=j;
							endd[i]=m;
							for(int s=j;s<=m;s++)b[s].value++; 
							result1++;
							break;
						}
					}
				}
				else if(v[i]>vv&&a[i]<0)
				{
					float temp;
					temp=d[i]+(float)(vv*vv-v[i]*v[i])/(float)(2*a[i]);
					bool beginb=true;
					for(int j=1;j<=m;j++)
					{
						if(q[j]>=d[i]&&beginb==true)
						{
							if((float)q[j]<temp)
							{
								beginn[i]=j;
								result1++;
								beginb=false;
							}
							else
							{
								break;
							}
						}
						if((float)q[j]<temp&&(j==m||q[j+1]>=temp))
						{
							endd[i]=j;b[j].value++;break;
						}
						if(beginb==false)b[j].value++;
					}
				}
				else if(v[i]<=vv&&a[i]>0)
				{
					float temp;
					temp=d[i]+(float)(vv*vv-v[i]*v[i])/(float)(2*a[i]);
					for(int j=1;j<=m;j++)
					{
						if((float)q[j]>(float)temp)
						{
							beginn[i]=j;
							endd[i]=m;
							for(int s=j;s<=m;s++)
							{
								b[s].value++;
							}
							result1++;
							break;
						}
					}
				}
			}
		}
		cout<<result1<<' ';
		msort(1,m);
		int result2=0;
		for(int j=1;j<=m;j++)
		{
			int temp=8;
			for(int k=1;k<=n;k++)
			{
				int kk=5;
				for(int s=beginn[k];s!=-0x7fffffff&&s<=endd[k];s++)
				{
					if(b[s].where==-0x7fffffff)
					{ 
					kk=6;break;
					} 
				}
				if(kk==5)
				{
					b[j].where=-0x7ffffff;result2++;break;
				} 
			} 
		}
		cout<<result2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
