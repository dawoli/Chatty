#include<bits/stdc++.h>
#define int long long
#define fst first
#define scd second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define antirep(i,a,b) for(int i=a;i>=b;i--)
#define speed ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=1e6+9,M=1e3+9,INF=1e9+7;
const double err=0.00001;
int n,m,l,vl,ans,T,cnt,wrong;
int d[N],v[N],a[N],p[N];
pair<int,int> e[N];
bool b[N]; 
void exceed(int x){
	if(v[x]>vl){cnt++;e[cnt].fst=d[x];e[cnt].scd=l;return;}//3 
	double ai=a[x]*1.0,vi=v[x]*1.0,si=d[x]*1.0;
	int s=ceil(si+(vl*vl-vi*vi)/(2.0*ai)-err);
	if(s-l>=0-err)return; //1 
	cnt++;e[cnt].fst=ceil(s),e[cnt].scd=l;//2 
	return;
}
void inceed(int x){
	if(v[x]<=vl)return;//7 
	double ai=-a[x]*1.0,vi=v[x]*1.0,si=d[x]*1.0;
	int s=floor(si+(vi*vi-vl*vl)/(2.0*ai)+err);
	if(s*1.0>l*1.0){cnt++;e[cnt].fst=d[x];e[cnt].scd=l;return;} //8 
	cnt++;e[cnt].fst=d[x],e[cnt].scd=floor(s);//6 
	return;
}
void equal(int x){
	if(v[x]<=vl) return;//4
	cnt++;e[cnt].fst=d[x];e[cnt].scd=l;//5
	return;
}
bool check(){
	rep(i,1,cnt)
		if(!b[i]&&e[i].scd!=l) return 0;
	return 1;
}
signed main(){
	speed;
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		wrong=0,cnt=0,ans=0;
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		memset(e,0,sizeof(e));
		cin>>n>>m>>l>>vl;
		rep(i,1,n)
			cin>>d[i]>>v[i]>>a[i];
		rep(i,1,m) cin>>p[i];
		sort(p+1,p+1+m);
		rep(i,1,n){
			if(a>0)	exceed(i);
			else if(a==0) equal(i);
			else if(a<0) inceed(i);
		}
		rep(i,1,cnt){
			int begin=e[i].fst,end=e[i].scd;
			int start=lower_bound(p+1,p+1+m,begin)-p,last=lower_bound(p+1,p+1+m,end)-p;
			if(start==last&&p[start]!=begin&&p[start]!=end) b[i]=1,wrong++;	
		}
		cout<<cnt-wrong<<' ';
		if(check()){
			cout<<m-1<<endl;
		}
		else
			cout<<m<<endl;
	}
	return 0;
}

