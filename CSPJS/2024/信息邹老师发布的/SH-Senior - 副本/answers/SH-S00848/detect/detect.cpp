#include <bits/stdc++.h>
using namespace std;
struct obj{
	double d,v,a;
	double exa,exb;
	bool exc,det;
};
obj c[100010];
int dt[100010];
int n,m,t;
double vlim,len,d[100010];
bool exdet(int cn)
{
	if(c[cn].exc==0)return 0;
	bool f;
	for(int i=1;i<=m;i++)
	{
		
		if(d[i]>c[cn].exb){
		break;}
		f=0;
		if(d[i]>=c[cn].exa&&d[i]<=c[cn].exb)
		{
			f=1;
			dt[i]++;
			
		}
	}
	if(f==1){return 1;}
	return 0;

}
void exdetn(int cn)
{
	if(c[cn].exc==0)return;
	
	for(int i=1;i<=m;i++)
	{
		
		if(d[i]>c[cn].exb){
		break;}
		
		if(d[i]>=c[cn].exa&&d[i]<=c[cn].exb)
		{
			
			dt[i]=1;
		}
	}
	
	return;

}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++)
	{for(int k=0;k<=100009;k++)
	{
		dt[k]=0;d[k]=0;c[k].a=0;
		c[k].d=0;c[k].v=0;c[k].exa=0;c[k].exb=0;c[k].exc=0;
		c[k].det=0;
	}
	
	cin>>n>>m>>len>>vlim;
	for(int i=1;i<=n;i++){
		cin>>c[i].d>>c[i].v>>c[i].a;
	}
	for(int i=1;i<=m;i++){cin>>d[i];}
	for(int i=1;i<=n;i++)
	{
		if(c[i].a==0&&c[i].v>vlim){
			c[i].exc=1;c[i].exa=c[i].d;c[i].exb=len;}
		if(c[i].a==0&&c[i].v<=vlim){c[i].exc=0;}
		if(c[i].a<0){
			if(c[i].v<=vlim){c[i].exc=0;}
			else
			{
				c[i].exc=1;
				double tmpex=(vlim*vlim-c[i].v*c[i].v)/(2*c[i].a);
				c[i].exa=c[i].d;c[i].exb=min(len,c[i].d+tmpex);		
			}
		}
		if(c[i].a>0)
		{
			if(c[i].v>vlim){c[i].exc=1;}
			if(c[i].v<=vlim)
			{
				double tmpex=(vlim*vlim-c[i].v*c[i].v)/(2*c[i].a);
				if(tmpex+c[i].d<=len){
					c[i].exc=1;c[i].exa=tmpex+c[i].d;c[i].exb=len;}
				else{c[i].exc=0;}
			}
		}
	}
	int cnt=0,cntd=0;
	for(int i=1;i<=n;i++)
	{
		if(exdet(i)){cnt++;
		}
		exdetn(i);
	}
	int maxx=0;
	for(int i=1;i<=m;i++)
	{
		if(dt[i]>maxx)maxx=dt[i];
	}
	cout<<cnt<<" "<<cnt-maxx+1<<endl;
	}
}
