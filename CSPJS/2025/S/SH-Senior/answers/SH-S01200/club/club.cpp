#include<bits/stdc++.h>;  
using namespace std;
const int Q=100005;
int d[Q][3];
int p[3];
int res[Q];
int t,n,a,b,c;
int sum(int m,int h,int o)
{
	if(p[1]<=n/2&&p[2]<=n/2&&p[3]<=n/2)
	{
		if(max(m,h)==m&&max(m,o)==m)
		{ 
		p[1]++;
		return m;
	    }
		if(max(m,h)==h&&max(h,o)==h) 
		{
		p[2]++;
			return h;
	    }
		if(max(m,o)==o&&max(h,o)==o) 
		{
			p[3]++;
			return o;
		}
		
	}
	if(p[1]<=n/2&&p[2]<=n/2&&p[3]>n/2)
	{
		if(max(m,h)==m) p[1]++;
		if(max(m,h)==h) p[2]++;
		return max(m,h);
	}
	if(p[1]<=n/2&&p[2]>n/2&&p[3]<=n/2)
	{
		if(max(m,o)==m) p[1]++;
		if(max(m,o)==o) p[3]++;
		return max(m,o);
	}
	if(p[1]>n/2&&p[2]<=n/2&&p[3]<=n/2)
	{
		if(max(h,o)==h) p[2]++;
		if(max(h,o)==o) p[3]++;
		return max(h,o);
	}
	if(p[1]<=n/2&&p[2]>n/2&&p[3]>n/2)
	{   p[1]++;
		return m;
	}
		if(p[1]>n/2&&p[2]<=n/2&&p[3]>n/2)
	{   p[2]++;
		return h;
	}
		if(p[1]>n/2&&p[2]>n/2&&p[3]<=n/2)
	{   p[3]++;
		return o;
	}
}
int dp(int x)
{
	int num=0;
	int q=sum(d[x][1],d[x][2],d[x][3]);
	
    if(x==0) num=0; 
  	else
	 num=dp(x-1)+q;
    return num;
}
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t,n,a,b,c;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
     {
     scanf("%d",&n);
	  for(int i=1;i<=n;i++)
	  {
	  	scanf("%d %d %d",&a,&b,&c);
	  	d[i][1]==a;
	  	d[i][2]==b;
	  	d[i][3]==c;
	  }
	   res[i]=dp(n);
	   memset(p,0,sizeof p);	
	 }
	 for(int i=0;i<t;i++)
	 {
	 	printf("%d\n",&res[i]);
	 }
	 return 0;
}
