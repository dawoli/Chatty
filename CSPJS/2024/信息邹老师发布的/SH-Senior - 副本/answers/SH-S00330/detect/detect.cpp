#include<cstdio>
#include<iostream>
#include<math.h>
using namespace std;
bool is_viable(int n,int m,int V,int *d,int *v,int *a,long double *l,bool *is_speeding,int *p,bool *enable)
{
	bool *speeding=new bool[n];
	for(int i=0;i<n;i++)
	{
		speeding[i]=false;
		for(int j=0;j<m;j++)
		{
			if((!enable[j])||p[j]<d[i])
				continue;
			if(p[j]>l[i])
				break;
			if(sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]))>V)
			{
				speeding[i]=true;
				break;
			}
		}
		if(speeding[i]!=is_speeding[i])
		{
			delete[] speeding;
			return false;
		}
	}
	delete[] speeding;
	return true;
}
void solve()
{
	int n,m,L,V;
	cin>>n>>m>>L>>V;
	int *d=new int[n],*v=new int[n],*a=new int[n],*p=new int[m];
	long double *l=new long double[n];
	bool *is_speeding=new bool[n];
	//d=start pos,v=velocity,a=acceleration,l=leave pos,p=camera pos
	for(int i=0;i<n;i++)
	{
		cin>>d[i]>>v[i]>>a[i];
		if(a[i]>=0)
			l[i]=L;
		else
			l[i]=(long double)(0-v[i]*v[i])/2/a[i]+d[i];
//		printf("l[%d]=%.3Lf\n",i,l[i]);
	}
	for(int i=0;i<m;i++)
		cin>>p[i];
	for(int i=0;i<n;i++)
	{
//		printf("%d:",i);
		is_speeding[i]=false;
		for(int j=0;j<m;j++)
		{
			if(p[j]<d[i])
				continue;
			if(p[j]>l[i])
				break;
//			printf("s(p[%d]=%d)=%.3lf,",j,p[j],sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i])));
			if(sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]))>V)
			{
//				printf("speeding");
				is_speeding[i]=true;
				break;
			}
		}
//		printf("\n");
	}
	int numbers_speeding=0;
	for(int i=0;i<n;i++)
		if(is_speeding[i])
			numbers_speeding++;
	cout<<numbers_speeding<<" ";
	int numbers_disabled=0,max_disabled=0;
	bool *enable=new bool[m];
	for(int i=0;i<m;i++)
		enable[i]=false;
	int carry;
	for(int i=0;i<(1<<m);i++)
	{
		carry=1;
		for(int j=0;j<m;j++)
		{
			if(!carry)
				break;
			else
			{
				enable[j]=(!enable[j]);
				if(!enable[j])
					carry=1;
				else
					carry=0;
			}
		}
		if(is_viable(n,m,V,d,v,a,l,is_speeding,p,enable))
		{
			numbers_disabled=0;
			for(int j=0;j<m;j++)
				if(!enable[j])
					numbers_disabled++;
			max_disabled=max(numbers_disabled,max_disabled);
		}
	}
	cout<<max_disabled<<endl;
	delete[] d;
	delete[] v;
	delete[] a;
	delete[] p;
	delete[] l;
	delete[] is_speeding;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
		solve();
}
