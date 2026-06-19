#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
struct car{int d,v0,a;}c[N];
int T,n,m,vv,l,lim[N];
void input(){
	cin>>n>>m>>l>>vv;
	for(int i=1;i<=n;i++)cin>>c[i].d>>c[i].v0>>c[i].a;
	for(int i=1;i<=m;i++)cin>>lim[i];
}
int ok[N];
double dis[N];//dis代表i号车最远到达的距离 
bool check(int l,int r){
	return upper_bound(lim+1,lim+1+m,r)==lower_bound(lim+1,lim+1+m,l);
}
void solve(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(c[i].v0>vv&&c[i].a>=0)cnt++,ok[i]=1;
		else if(c[i].v0<vv&&c[i].a<=0)ok[i]=1;
		else if(c[i].v0==vv&&c[i].a==0)ok[i]=1;
	}
	int rr=1,ll=n;
	for(int i=1;i<=n;i++){
		if(ok[i])continue;
		dis[i]=(vv*vv-c[i].v0*c[i].v0)/2.0/c[i].a;
		double pos=c[i].d+dis[i];
		if(c[i].a>0){
			if(pos<(double)lim[m])
				rr=max(rr,(int)floor(pos*1.0)),cnt++;
		}
		else { 
			if(!check(c[i].d,pos))////[c[i].d,pos]有车站
				ll=min(ll,(int)ceil(pos*1.0)),cnt++;
		}
	}
	cout<<cnt<<" "<<ll<<endl;
}


bool judgea0(){
	for(int i=1;i<=n;i++)
		if(c[i].a!=0)return 0;
	return 1;
}
void solvea0(){
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(c[i].v0>vv)cnt++;
	cout<<cnt<<" "<<m-1<<endl;
}
void ssolve(){
	cin>>T;
	for(int i=1;i<=T;i++){
		input();
		sort(lim+1,lim+1+m);
		if(judgea0())solvea0();
		else solve();
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ssolve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
