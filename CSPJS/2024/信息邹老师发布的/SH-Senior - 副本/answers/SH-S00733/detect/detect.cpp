#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN=100005;
int n,m,L,V;
int fastcar=0;
struct car
{
	int v0,a,d;
	bool twf[3005];//test_will_fast
	bool ct;
 }c[3005];
 
 
struct test
{
 	int node,car;	
};



int t[3005];
test tc[3005];


double calv(int v,int A,int T)
{
	double ans=sqrt(v*v+2*A*T);
	return ans;
}


bool cmp(test x,test y)
{
	return x.car>y.car;
}


void memset()
{
	for(int i=1;i<=3000;i++)
		tc[i].car=0;
}

int choice[3005];

bool check(int nft)//n_for_test
{
	bool C[n+1]={false};
	for(int i=1;i<=nft;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(c[j].twf[choice[i]]==true)
				C[j]=true;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if((C[i]==false)&&(c[i].ct==true))
			return false;
	}
	return true;
}

bool ttmp=false;

void f(int k,int t)
{
	if(t==0)
	{
		if(check(k))
			ttmp=true;
		return ;
	}
	for(int i=1;i<=m;i++)
	{
		if(tc[i].car==0)
			continue;
		choice[k-t+1]=tc[i].node;
		f(k,t-1);
		if(ttmp)
			return ;
	}
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int g=1;g<=T;g++)
	{
		memset();
		fastcar=0;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&c[i].d,&c[i].v0,&c[i].a);
			c[i].ct=false;
			for(int j=1;j<=m;j++)
				c[i].twf[j]=0;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&t[i]);
			tc[i].node=i;
		}
		for(int i=1;i<=n;i++)
		{
			bool tmp=false;
			for(int j=1;j<=m;j++)
			{
				if(c[i].d>t[j])
					continue;
				if((c[i].v0*c[i].v0+2*c[i].a*(t[j]-c[i].d))<0)
					break;
				double v=calv(c[i].v0,c[i].a,t[j]-c[i].d);
			//	cout<<i<<' '<<v<<' '<<t[j]<<endl;
				if(v>double(V))
				{
					tmp=true;
					tc[j].car++;
					c[i].twf[j]=true;
					c[i].ct=true;
				}
				if(c[i].a<0&&v<double(V))
					break;
			}
			if(tmp)
				fastcar++;
		}
		sort(tc+1,tc+m+1,cmp);
		int rt=0;//remain_test
		
		for(int i=1;i<=m;i++)
		{
			ttmp=false;
			f(i,i);
			if(ttmp)
			{
				rt=i;
			//	cout<<i<<endl;
				break;
			}
		}
		
		
		
/*	for(int i=1;i<=n;i++)
		{
			cout<<i<<' '<<c[i].ct<<endl;
			for(int j=1;j<=m;j++)
				cout<<c[i].twf[j]<<' ';
			cout<<endl;
			}
		for(int i=1;i<=m;i++)
		{
			cout<<tc[i].node<<' '<<tc[i].car<<endl;
		}*/
		
		
	/*	for(int i=1;i<=m;i++)
		{
			bool tmp=false;
			for(int j=1;j<=n;j++)
			{
				if(c[j].twf[tc[i].node]==true&&c[j].ct==false)
				{
					tmp=true;
					c[j].ct=true;
				}
			}
			if(tmp)
			{
				rt++;
				cout<<tc[i].node<<' '<<t[tc[i].node]<<endl; 
			}
		}*/
		int anwser=m-rt;
		printf("%d %d\n",fastcar,anwser);
	//	cout<<fastcar<<" "<<m-rt<<endl;
	}
	return 0;
 } 
