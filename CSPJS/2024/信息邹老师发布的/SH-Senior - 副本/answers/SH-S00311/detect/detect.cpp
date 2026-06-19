//100
#include<bits/stdc++.h>
using namespace std;
#define ll long long
char z;
int ww,ret;
int read()
{
	z=0,ww=1,ret=0;
	while((z>'9'||z<'0')&&z!='-') z=getchar();
	if(z=='-') ww=-1,z=getchar();
	while(z<='9'&&z>='0') ret=(ret<<1)+(ret<<3)+(z^48),z=getchar();
	return ret*ww;
}
const int N=100005;
struct node{
	int l,r;//int
	bool operator <(const node& p) const{
		if(r==p.r) return l>p.l;
		return r<p.r;
	}
}c[N];//car
int p[N];
int n,m,L,v;
int disfloor(int v0,int v1,int a){return (v1*v1-v0*v0)/(2*a);}
int disceil(int v0,int v1,int a){return (v1*v1-v0*v0-1)/(2*a)+1;}
node calc_road(int d,int v0,int a)
{
	if(v0>v)
	{
		if(a>=0) return node{d,L};
		else return node{d,min(d+disceil(v,v0,-a)-1,L)};
	} 
	else
	{
	 	if(a<=0) return node{-1,-1};
	 	else 
	 	{
	 		int tmp=disfloor(v0,v,a)+1+d;
	 		if(tmp>L) return node{-1,-1};
	 		else return node{tmp,L};
		}
	}
}
node calc_bar(int l,int r)
{
	int a=lower_bound(p+1,p+m+1,l)-p;//smallest >= n number,possibly over max
	int b=upper_bound(p+1,p+m+1,r)-p-1;//biggest <=n number
	if(a>b) return node{-1,-1};
	else return node{a,b};
}
void my_main()
{
	n=read(); m=read(); L=read(); v=read();
//	scanf("%d%d%d%d",&n,&m,&L,&v);
	int cnt=0,td,tv,ta;
	node x;
	while(n--)
	{
		td=read(); tv=read(); ta=read();
//		scanf("%d%d%d",&td,&tv,&ta);
		x=calc_road(td,tv,ta);
//		printf("GET [%d,%d]\n",x.l,x.r);
		if(x.l==-1) continue;
		cnt++;
		c[cnt]=x;
	}
	for(int j=1;j<=m;j++) p[j]=read();//scanf("%d",&p[j]);
	if(cnt==0)
	{
		printf("0 %d\n",m);
		return;
	}
	n=cnt;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		x=calc_bar(c[i].l,c[i].r);
//		printf("SOL [%d,%d]\n",x.l,x.r);
		if(x.l==-1) continue;
		cnt++;
		c[cnt]=x;
	}
	n=cnt;
	if(cnt==0)
	{
		printf("0 %d\n",m);
		return;
	}
	printf("%d ",n);
	int cur=-1;
	cnt=0;
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)
	{
		if(c[i].l>cur)
		{
			cnt++;
			cur=c[i].r;
		}
	}
	printf("%d\n",m-cnt);
} 
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
//	double st=clock();
	int qwq;
	qwq=read();
	while(qwq--) my_main();
//	double ed=clock();
//	printf("%.3lf",(ed-st)/1000);
	return 0;
}

