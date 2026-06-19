#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int N=1e5+4;
int n,m,l;
double vm,d[N],v[N],a[N],p[N];
double eps=0.0000000001;
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar();
	}
	return res*f;
}
bool vis[27];
int res;
int ans,ans1;
bool check(){
	double mx=-1.0;
	for(int i=1;i<=m;++i){
		if(vis[i]) mx=max(mx,p[i]);
	}
	int sum=0;
	for(int i=1;i<=n;++i){
		if(a[i]>-eps && a[i]<eps){
			if(mx-d[i]>=-eps && v[i]-vm>=eps) ++sum;
		}
		else if(a[i]>0){
			if(d[i]-mx>=eps) continue;
			if(sqrt(v[i]*v[i]+2.0*a[i]*(mx-d[i]))-vm>=eps)
				++sum;
		}
		else if(a[i]<0){
			for(int j=1;j<=m;++j)
				if(vis[j] && p[j]-d[i]>=-eps && sqrt(v[i]*v[i]+2.0*a[i]*(p[j]-d[i]))-vm>=eps){
					++sum; 
					break;
				}
		}
	}
	return sum==ans;
}
void dfs(int now,int sel){
	if(now>m){
		if(check()) res=min(res,sel);
		return ;
	}
	vis[now]=1;
	dfs(now+1,sel+1);
	vis[now]=0;
	dfs(now+1,sel);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T; cin>>T;
	while(T--){
		res=100;
		ans=0,ans1=0;
		double maxp=-1.0;
		n=read(); m=read(); l=read();
		vm=read()*1.0;
		int cnt0=0,cntz=0,cntf=0;
		for(int i=1;i<=n;++i){
			d[i]=read()*1.0; v[i]=read()*1.0; a[i]=read()*1.0;
			if(a[i]>-eps && a[i]<eps) ++cnt0;
			else if(a[i]>0) ++cntz;
			else if(a[i]<0) ++cntf;
		} 
		for(int i=1;i<=m;++i){
			p[i]=read()*1.0;
			maxp=max(maxp,p[i]);
		} 
		if(cnt0==n){//A
			for(int i=1;i<=n;++i) 
				if(maxp-d[i]>=-eps && v[i]-vm>=eps) ++ans;
			if(ans!=0) cout<<ans<<' '<<m-1<<'\n';
			else if(ans==0) cout<<ans<<' '<<m<<'\n';
			continue;
		}
		else if(cntz==n){//B
			for(int i=1;i<=n;++i){
				if(d[i]-maxp>=eps) continue;
				if(sqrt(v[i]*v[i]+2.0*a[i]*(maxp-d[i]))-vm>=eps)
					++ans;
			}
			if(ans!=0) cout<<ans<<' '<<m-1<<'\n';
			else if(ans==0) cout<<ans<<' '<<m<<'\n';
			continue;
		}
		else if(n<=20 && m<=20){
			for(int i=1;i<=n;++i){
				if(a[i]>-eps && a[i]<eps){
					if(maxp-d[i]>=-eps && v[i]-vm>=eps) ++ans;
				}
				else if(a[i]>0){
					if(d[i]-maxp>=eps) continue; 
					if(sqrt(v[i]*v[i]+2.0*a[i]*(maxp-d[i]))-vm>=eps)
						++ans;
				}
				else if(a[i]<0){
					for(int j=1;j<=m;++j)
						if(p[j]-d[i]>=-eps && sqrt(v[i]*v[i]+2.0*a[i]*(p[j]-d[i]))-vm>=eps){
							++ans; 
							break;
						}
				}
			}
			dfs(1,0);
			cout<<ans<<' '<<m-res<<'\n';
			continue;
		}
	}
	return 0;
}
