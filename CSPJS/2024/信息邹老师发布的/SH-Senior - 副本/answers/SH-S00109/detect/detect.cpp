#include<bits/stdc++.h>
using namespace std;
int n,m,l,maxv,i,j,p[200001]={0},ans=0,k,t,dp[200001];
bool is[200001];
struct c
{
	int d;
	int v;
	int a;
	int passl;
	//int passr;
}car[200001];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t; 
	for(k=1;k<=t;k++)
	{
	cin>>n>>m>>l>>maxv;
	ans=0;
	for(i=1;i<=n;i++)
	{
		cin>>car[i].d>>car[i].v>>car[i].a;
		if(car[i].a>0)
		{
			if((maxv*maxv-car[i].v*car[i].v)%(2*car[i].a)!=0)
				car[i].passl=(maxv*maxv-car[i].v*car[i].v)/(2*car[i].a)+1+car[i].d;
			else
				car[i].passl=(maxv*maxv-car[i].v*car[i].v)/(2*car[i].a)+car[i].d;
			//car[i].passr=l;
		}
		if(car[i].a==0)
		{
			if(car[i].v>maxv)
				car[i].passl=car[i].d;
			else
				car[i].passl=l+1000;
			//car[i].passr=l;
		}/*
		if(car[i].a<0)
		{
			if(car[i].v<=maxv)
			{
				car[i].passl=l+1000;
				car[i].passr=l+1001;
			}
			else
			{
				car[i].passl=car[i].d;
				if((maxv*maxv-car[i].v*car[i].v)%(2*car[i].a)!=0)
					car[i].passr=(maxv*maxv-car[i].v*car[i].v)/(2*car[i].a)-1+car[i].d;
				else
					car[i].passr=(maxv*maxv-car[i].v*car[i].v)/(2*car[i].a)+car[i].d;
			}
		}*/
	}
	for(i=1;i<=m;i++)
	{
		cin>>p[i];
	}
	for(j=1;j<=n;j++)
	{
		if(car[j].passl<=p[m])
		{
			ans++;
		}
	}
	cout<<ans<<" "<<m-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
