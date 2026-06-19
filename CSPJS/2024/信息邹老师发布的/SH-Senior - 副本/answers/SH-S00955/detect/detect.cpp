#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,lj[N];
double L,V;
double p[N],rin[N],rout[N];
const double MIN= 1e-6;
struct car{
	double d,v,a;
	void proc(){
		printf("%d",d);
	}
} c[N];

double trs(car aa){
	if(aa.a==0) return -1;
	double x1=(V-aa.v)/aa.a;
	return x1;
}
double trz(car aa){
	if(aa.a>0||aa.a==0) return -1;
	double x1=(-aa.v)/aa.a;
}
double ctt(car aa, double ti){
	double cnt=aa.a*ti*ti/2+aa.v*ti+aa.d;
	return cnt;
}
void proc(car ca,int th){
	double ac=ca.a, v0=ca.v, ini=ca.d;
	if(ac>0){
		if(v0>V) rin[th]=ini, rout[th]=L;
		else if (v0==V) rin[th]=ini+MIN, rout[th]=L;
		else{
			double lrs= ctt(ca, trs(ca));
			if ( lrs > L ) rin[th]=rout[th]=-1;
			else rin[th]=lrs+MIN, rout[th]=L;
		}
	}
	else if(ac==0){
		if(v0>V) rin[th]=ini, rout[th]=L;
		else rin[th]=rout[th]=-1;
	}
	else{
		if(v0>V){
			
			double lrs= ctt(ca, trs(ca));
			rin[th]=ini, rout[th]=lrs-MIN;
		}
		else rin[th]=rout[th]=-1;
	}
}
struct seg{
	double lef, ri;
	bool operator<(seg aa){
		return ri<aa.ri;
	}
} os[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int ttt,ddd=0;
	scanf("%d",&ttt);
	while(scanf("%d%d%lf%lf",&n,&m,&L,&V))
{
	ddd++;
	for(int i=1;i<=n;i++)
	scanf("%lf%lf%lf",&c[i].d,&c[i].v,&c[i].a);
	for(int i=1;i<=m;i++) scanf("%lf",&p[i]);
	for(int i=1;i<=n;i++) proc(c[i],i);
	for(int i=1;i<=n;i++) os[i].lef=rin[i],os[i].ri=rout[i];
	sort(os+1,os+n+1);
	sort(p+1,p+m+1);
	int it=1;
	int caa=0,cnt=0;
	for(int i=1;i<=n;i++) lj[i]=0;
	for(int i=1;i<=n;i++){
		//printf("%d %d %d\n",caa,cnt,it);
		if(os[i].ri<0) lj[i]=1;
		if(lj[i]==1) continue;
		if(it!=0&&os[i].lef<p[it]) lj[i]=1,caa++;
		if(lj[i]==1) continue;
		while(p[it]<os[i].lef&&it<m&&p[it+1]<=os[i].ri) it++;
		
		if(p[it]>=os[i].lef&&p[it]<=os[i].ri) cnt++,caa++;
	}
	//for(int i=1;i<=n;i++)
	//printf("%lf %lf\n",os[i].lef,os[i].ri);
	printf("%d %d\n",caa,m-cnt);
	if(ddd>=ttt) break;
}
	return 0;
}
