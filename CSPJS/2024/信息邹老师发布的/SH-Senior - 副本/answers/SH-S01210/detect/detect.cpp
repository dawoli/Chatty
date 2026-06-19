#include<bits/stdc++.h>
using namespace std;
struct c
{
	int d;
	int v;
	int a;
}car[5000];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	double k,n,m,l,V;
	int dec[3000],add[5000];
	
	cin>>k;
	for(int p=1;p<=k;p++)
	{
	int ans=0,cnt=0;
	memset(add,0,sizeof 0);
	cin>>n>>m>>l>>V;
	for(int i=1;i<=n;i++)
		cin>>car[i].d>>car[i].v>>car[i].a;
	for(int i=1;i<=m;i++)
		cin>>dec[i];
	for(int i=1;i<=n;i++)
	{	double near;
		double v1,v2;
		for(int j=1;j<=m;j++)
			if(dec[j]>=car[i].d)
			{
				near=dec[j];
				break;
			}
		if(car[i].a==0)
			if(car[i].v>V)
				ans++;	
		if(car[i].a<0&&car[i].v>V)
		{
			int now1=car[i].v*car[i].v+2*car[i].a*(near-car[i].d);
			if(now1>=0)
				v1=sqrt(now1);
			else v1=0;
			if(v1>V)
				ans++;
		}
		if(car[i].a>0)
		{
			double now2=car[i].v*car[i].v+2*car[i].a*(dec[m]-car[i].d);
			v2=sqrt(now2);
			if(v2>V)
				ans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(car[i].a>0)
		{
			double s;
			s=(V*V-car[i].v*car[i].v)/2/car[i].a;
			for(int j=1;j<=m;j++)
			{
				if(dec[j]>(s+car[i].d))
					add[j]=1;
			}
		}
		if(car[i].a==0&&car[i].v>V)
		{
			for(int j=1;j<=m;j++)
			if(dec[j]>=car[i].d)
			add[j]=1;
		}
		if(car[i].a<0&&car[i].v>V)
		{
			double s;
			s=(car[i].v*car[i].v-V*V)/2/car[i].a;
			for(int j=1;j<=m;j++)
			{
				if(dec[j]>=car[i].d&&dec[j]<s+car[i].d)
				add[i]=1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	if(add[i]==0)
		cnt++;
	cout<<ans<<" ";
	cout<<cnt;
	cout<<endl; 
	}
	return 0;
//5 5 15 3
//0 3 0
//12 4 0
//1 1 4
//5 5 -2
//6 4 -4
//2 5 8 9 15
}
