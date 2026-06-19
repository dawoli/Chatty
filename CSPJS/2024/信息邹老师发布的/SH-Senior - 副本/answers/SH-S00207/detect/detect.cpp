#include<bits/stdc++.h>
using namespace std;
const int N=100020;
bool vst[N];
int T,n,m,mm,L,V,p[N],pp[N],ans0,ans1=0;
struct Car{
	int d,v,a;
}c[N];
int solvelimit(){
	//计算mm个测速仪开启时超速的车的数量
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(c[i].a>0){
			//若车辆加速行驶
			for(int j=1;j<=mm;j++)
				if(pp[j]>=c[i].d){
					double spd=sqrt(c[i].v*c[i].v*1.0+2*c[i].a*(pp[j]-c[i].d)*1.0);
					double lmt=V*1.0;
					if(spd>lmt){cnt++;break;}
				}
		}
		else if(c[i].a==0){
			for(int j=1;j<=mm;j++)
				if(pp[j]>=c[i].d)
					if(c[i].v>V){cnt++;break;}
		}
		else{
			for(int j=1;j<=mm;j++)
				if(pp[j]>=c[i].d){
					int xx=c[i].v*c[i].v+2*c[i].a*(pp[j]-c[i].d);
					if(xx<0)continue;
					double spd=sqrt(xx*1.0);
					double lmt=V*1.0;
					if(spd>lmt){cnt++;break;}
				}
		}
	}
	return cnt;
}
void copy(){
	mm=0;
	for(int i=1;i<=m;i++)
		if(vst[i])pp[++mm]=p[i];
}
void dfs(int cur,int cnt){//测速仪选或不选 
	if(cur==m+1){
		copy();
		if(solvelimit()==ans0)
			ans1=max(ans1,m-cnt);
		return;
	}
	vst[cur]=0;
	dfs(cur+1,cnt);
	vst[cur]=1;
	dfs(cur+1,cnt+1);
}
void solveBF(){
	mm=m;
	for(int i=1;i<=mm;i++)
		pp[i]=p[i];
	ans0=solvelimit();
	cout<<ans0<<" ";
	fill(vst+1,vst+1+N,0);
	ans1=0;
	dfs(1,0);
	cout<<ans1<<endl;
}
bool alladd0(){
	for(int i=1;i<=n;i++)
		if(c[i].a<0)return 0;
	return 1;
}
void solveadd0(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(c[i].d>p[m])continue;
		double spd=sqrt(c[i].v*c[i].v*1.0+2*c[i].a*(p[m]-c[i].d)*1.0);
		double lmt=V*1.0;
		if(spd>lmt)cnt++;
	}
	cout<<cnt<<" "<<m-1<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
//计算瞬时速度：sqrt(v0*v0*1.0+2*a*s*1.0)
//计算瞬时速度对应位移：((v1*v1-v0*v0)*1.0)/(2*a*1.0) 
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
			cin>>c[i].d>>c[i].v>>c[i].a;
		for(int i=1;i<=m;i++)cin>>p[i];
		if(n<=20&&m<=20)solveBF();
		else if(alladd0())solveadd0();
	}
	return 0;
}
