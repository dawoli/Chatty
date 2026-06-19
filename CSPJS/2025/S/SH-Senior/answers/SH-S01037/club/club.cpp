#include<bits/stdc++.h>
using namespace std;
long long n,sum,mx;
bool A,B,v1[100005],v2[100005];
struct str
{
	long long a,b,c;
}m[100005],g[100005];
bool cmp(str x,str y)
{
	return x.a>=y.a;
}
bool cmp1(str x,str y)
{
	return x.b>=y.b;
}
void solve(long long d,long long e,long long f,long long k,long long zo,long long i)
{
	if(i==k+1)
	{
		mx=max(mx,zo);
		return;
	}
	if(d+1<=k/2)
	{
		solve(d+1,e,f,k,zo+m[i].a,i+1);
	}
	if(e+1<=k/2)
	{
		solve(d,e+1,f,k,zo+m[i].b,i+1);
	}
	if(f+1<=k/2)
	{
		solve(d,e,f+1,k,zo+m[i].c,i+1);
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		mx=0;
		for(int j=1;j<=x;j++)
		{
			v1[j]=0;
			v2[j]=0;
			long long y,p,o;
			cin>>y>>p>>o;
			m[j].a=y;
			m[j].b=p;
			m[j].c=o;
			sum+=max(max(o,p),y);
			if(p!=0||o!=0)
			{
				A=1;
			}
			if(o!=0)
			{
				B=1;
			}
		}
		if(A==0)
		{
			sort(m+1,m+x+1,cmp);
			sum=0;
			for(int j=1;j<=x/2;j++)
			{
				sum+=m[j].a;
			}
			cout<<sum<<endl;
			return 0;
		}
		else if(B==0)
		{
			sum=0;
			for(int j=1;j<=x;j++)
			{
				g[j].a=m[j].a;
				g[j].b=m[j].b;
				g[j].c=j;
			}
			sort(g+1,g+x+1,cmp);
			for(int j=1;j<=x/2;j++)
			{
				v1[g[i].c]=1;
				sum+=g[j].a;
			}
			sort(g+1,g+x+1,cmp1);
			for(int j=1;j<=x/2;j++)
			{
				v2[g[i].c]=1;
				sum+=g[j].b;
			}
			long long cnt=0,cnt1=0,l[100005],r[100005];
			for(int j=1;j<=x;j++)
			{
				if(v1[j]==v2[j])
				{
					cnt++;
					l[cnt]=j;
				}
				if(v1[j]==0&&v2[j]==0)
				{
					cnt1++;
					r[cnt1]=j;
				}
			}
			for(int j=1;j<=cnt;j++)
			{
				if(m[l[j]].a-m[r[j]].a<=m[l[j]].b-m[r[j]].b)
				{
					sum-=(m[l[j]].a-m[r[j]].a);
				}
				else
				{
					sum-=(m[l[j]].b-m[r[j]].b);
				}
			}
			cout<<sum<<endl;
		}
		else
		{
		if(x>25)
		{
			cout<<sum<<endl;
		}
		else
		{
			solve(0,0,0,x,0,1);
			cout<<mx<<endl;
		}
		}
	}
	return 0;
}
