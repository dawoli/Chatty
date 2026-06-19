#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long x=0,f=1;
	char ch;
	ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

struct CAR{
	double d,v,a;
	long long first,last;
}car[100005];

struct CAR1{
	long long first,last;
}car1[100005];
long long p[100005];
long long ptimes[100005];
long long n,m,ans2;
long long ans1;

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	long long T;
	T=read();
	while(T--)
	{
		memset(ptimes,0,sizeof(ptimes));
		memset(p,0,sizeof(p));
		long long L,V;
		long long ans=0;
		ans1=0;
		n=read();
		m=read();
		L=read();
		V=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&car[i].d);
			scanf("%lf",&car[i].v);
			scanf("%lf",&car[i].a);
			car[i].first=0;
			car[i].last=0;
		}
		for(int i=1;i<=m;i++) p[i]=read();
		stable_sort(p+1,p+m+1);
		for(int i=1;i<=n;i++)
		{
			if(car[i].a==0)
			{
				if(car[i].v>V&&car[i].d<=p[m])
				{
					car[i].first=lower_bound(p+1,p+m+1,car[i].d)-p;
					car[i].last=m;
					ans++;
				}
			}
			else if(car[i].a>0)
			{
				if(car[i].v>V&&car[i].d<=p[m])
				{
					car[i].first=lower_bound(p+1,p+m+1,car[i].d)-p;
					car[i].last=m;
					ans++;
				}
				else if(car[i].v==V&&car[i].d<p[m])
				{
					car[i].first=upper_bound(p+1,p+m+1,car[i].d)-p;
					car[i].last=m;
					ans++;
				}
				else if(car[i].v<V)
				{
					double s;
					s=((double)V*(double)V-(double)car[i].v*(double)car[i].v)/((double)2*(double)car[i].a);
					if((double)car[i].d+s<p[m])
					{
						car[i].first=lower_bound(p+1,p+m+1,(double)car[i].d+s)-p;
						if(abs((double)p[car[i].first]-(double)car[i].d+s)<1) car[i].first++;
						car[i].last=m;
						ans++;
					}
				}
			}
			else
			{
				if(car[i].v==V)
				{
					int x;
					x=lower_bound(p+1,p+m+1,car[i].d)-p;
					if(p[x]==car[i].d)
					{
						ans++;
						car[i].first=x;
						car[i].last=x;
					}
				}
				else if(car[i].v>V)
				{
					double s;
					s=((double)V*(double)V-(double)car[i].v*(double)car[i].v)/((double)2*(double)car[i].a);
					int x=lower_bound(p+1,p+m+1,car[i].d)-p;
					int y=lower_bound(p+1,p+m+1,(double)car[i].d+s)-p;//x<y
					if(abs((double)p[y]-(double)car[i].d+s)<1) y--;
					if(p[x]<=((double)car[i].d+s)&&x<=y)
					{
						car[i].first=x;
						car[i].last=y;
						ans++;
					}
				}
			}
		}
		write(ans);
		printf(" ");
		//for(int i=1;i<=m;i++) cout<<car[i].first<<" "<<car[i].last<<endl; 
		for(int i=1;i<=m;i++)
		{
			car1[i].first=car[i].first;
			car1[i].last=car[i].last;
		}
		int cnt=0,flag=0;
		while(flag==0)
		{
			flag=1;
			memset(ptimes,0,sizeof(ptimes));
			for(int i=1;i<=n;i++)
			{
				for(int j=max((long long)1,car[i].first);j<=car[i].last;j++)
				{
					ptimes[j]++;
				}
			}
			int maxn=0,mm;
			for(int i=1;i<=m;i++)
			{
				if(maxn<ptimes[i])
				{
					maxn=ptimes[i];
					mm=i;
				}
			}
			cnt++;
			for(int i=1;i<=n;i++)
			{
				if(mm>=car[i].first&&mm<=car[i].last)
				{
					car[i].first=0;
					car[i].last=0;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(car[i].first!=0)
				{
					flag=0;
					break;
				}
			}
		}
		ans1=m-cnt;
		cnt=0;
		flag=0;
		while(flag==0)
		{
			flag=1;
			memset(ptimes,0,sizeof(ptimes));
			for(int i=1;i<=n;i++)
			{
				for(int j=max((long long)1,car1[i].first);j<=car1[i].last;j++)
				{
					ptimes[j]++;
				}
			}
			int maxn=0,mm;
			for(int i=1;i<=m;i++)
			{
				if(maxn<=ptimes[i])
				{
					maxn=ptimes[i];
					mm=i;
				}
			}
			cnt++;
			for(int i=1;i<=n;i++)
			{
				if(mm>=car1[i].first&&mm<=car1[i].last)
				{
					car1[i].first=0;
					car1[i].last=0;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(car1[i].first!=0)
				{
					flag=0;
					break;
				}
			}
		}
		ans1=min(ans1,m-cnt);
		write(ans1);
		printf("\n");
	}
	return 0;
}
