#include<bits/stdc++.h>
using namespace std;
int T,locx,locy,locd,nextx,nexty,nextd,times,k;
bool ktimes;
int cnt[6]={1,1,1,1,1,1};
char S[1001][1002];
void f()
{
	if(nextd==0)
	{
		nextx=locx;
		nexty=locy+1;
	}
	else if(nextd==1)
	{
		nextx=locx+1;
		nexty=locy;
	}
	else if(nextd==2)
	{
		nextx=locx;
		nexty=locy-1;
	}
	else if(nextd==3)
	{
		nextx=locx-1;
		nexty=locy;
	}
}
bool g()
{
	return S[nextx][nexty]=='.';
}
void h()
{
	while(!g())
	{
		nextd+=1;
		if(nextd==4)
		{
			nextd=0;
		}
		times+=1;
		if(times==k)
		{
			ktimes=true;
		}
		f();
	}
	locx=nextx,locy=nexty,locd=nextd;
	times+=1;
	if(times==k)
	{
		ktimes=true;
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i+=1)
	{
		int n,m;
		cin>>n>>m>>k;
		int x0,y0,d0;
		cin>>x0>>y0>>d0;
		nextx=locx=x0,nexty=locy=y0,nextd=locd=d0;
		int times=0;
		ktimes=false;
		bool get[n+1][m+1];
		for(int j=1;j<=n;j+=1)
		{
			for(int k=1;k<=m;k+=1)
			{
				cin>>S[j][k];
				get[j][k]=false;
			}
		}
		while(!ktimes)
		{
			f();
			h();
			if(!get[nextx][nexty])
			{
				get[nextx][nexty]=true;
				cnt[i]+=1;
			}
		}
	}
	for(int i=1;i<=T;i+=1)
	{
		cout<<cnt[i]<<'\n';
	}
	return 0;
}
