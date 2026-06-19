#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iomanip>
using namespace std;
struct car{
	double d,v,a,acpos=9223372036854775807;
	bool dir=false;//方向反转 
}c[100010];
double p[100010],l,v;
bool cmp(double a,double b){
	return a<b;
}
int n,m,cnt=0,ans2=0;
void initialize(){
	cnt=0;
	ans2=0;
	for(int i=0;i<10000;++i) p[i]=c[i].d=c[i].v=c[i].a=0.00;
}
bool tak[100010]={false};
bool check(int x){
	for(int i=0;i<m;++i){
		if(!c[x].dir) if(p[i]>=c[x].acpos&&!tak[i]) return true;
		if(c[x].dir) if(p[i]<=c[x].acpos&&!tak[i]) return true;
	}
	return false;
}
void cont(int step=0,int ncnt=0){
	if(ncnt+m-step<ans2) return;//最优化剪枝
	for(int i=0;i<n;++i){
		if(!c[i].dir) if(c[i].acpos<=p[m-1]) if(!check(i)) return;
		if(c[i].dir) if(c[i].acpos>=p[0]) if(!check(i)) return;
	}
	if(step==m){
		ans2=max(ans2,ncnt);
		return;
	}
	tak[step]=true;
	cont(step+1,ncnt+1);
	tak[step]=false;
	cont(step+1,ncnt);
}
//本题中，加速度正负需要分开讨论 
void solve(){
	initialize();
	int ans=0;
	cin>>n>>m>>l>>v;
	for(int i=0;i<n;++i) cin>>c[i].d>>c[i].v>>c[i].a;
	for(int i=0;i<m;++i) cin>>p[i];
	sort(p,p+m,cmp);
	for(int i=0;i<n;++i){
		if(c[i].a<0) continue;
		if(c[i].a==0){if(c[i].v>v) c[i].acpos=0; continue;}
		c[i].acpos=(v*v-c[i].v*c[i].v)/(2*c[i].a)+c[i].d;
	}
	for(int i=0;i<n;++i){
		if(c[i].a>=0) continue;
		c[i].dir=true;
		if(c[i].v<v) continue;
		double t=(c[i].v-v)/(-c[i].a);
		c[i].acpos=t*c[i].v+0.5*c[i].a*t*t+c[i].d;
	}
	for(int i=0;i<n;++i){
		if(!c[i].dir) ans=c[i].acpos>p[m-1]?ans:ans+1;
		if(c[i].dir) ans=c[i].acpos<p[0]?ans:ans+1;
	}
	cont();
	cout<<ans<<" "<<ans2<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;++i) solve();
	return 0;
}
/*
匀加速运动公式
时间位移s=v0*t+0.5*a*t^2 
消时公式s=(vt*vt-v0*v0)/2a
*/ 
