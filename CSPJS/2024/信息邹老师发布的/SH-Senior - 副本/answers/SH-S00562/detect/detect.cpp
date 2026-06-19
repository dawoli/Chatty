#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define Rep(i,l,r) for(int i=(l);i>=(r);i--)
#define INF 1e9
#define gc getchar()
#define int long long
using namespace std;
namespace fastIO{
	int read(){
		int x=0,f=1;char ch=gc;
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=-1;
			ch=gc;
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc;
		return x*f;
	}
}
using namespace fastIO;
const int N=100009;
int T;
int n,m,l,V,d[N],v[N],a[N],p[N],deg[N],ans[N];
bool od[N];
vector<int> e[N];
vector<int> nll;
long double tp=1.0;
void add(int x){
	if(a[x]==0){
		if(v[x]<=V){
//			cout<<1<<endl;
			return;
		}
		int lst=lower_bound(p+1,p+m+1,d[x])-p;
		if(lst==(m+1)){
//			cout<<2<<endl;
			return;
		}
		e[lst-1].push_back(m);
		deg[m]++;
		od[x]=1;
	}
	else if(a[x]>0){
		int ovr;
		if(v[x]>V){
			ovr=d[x];
		}
		else{
			ovr=d[x]+ceil(tp*(V*V-v[x]*v[x])/(2*a[x]));
			if((V*V-v[x]*v[x])%(2*a[x])==0) ovr++;
		}
		int lst=lower_bound(p+1,p+m+1,ovr)-p;
		if(lst==(m+1)){
//			cout<<3<<endl;
			return;
		}
		e[lst-1].push_back(m);
		deg[m]++;
		od[x]=1;
	}
	else{
		if(v[x]<=V){
//			cout<<4<<endl;
			return;
		}
		int st=lower_bound(p+1,p+m+1,d[x])-p;
		a[x]=-a[x];
		int ed=d[x]+ceil(tp*(v[x]*v[x]-V*V)/(2*a[x]));
//		if((v[x]*v[x]-V*V)%(2*a[x])==0) ed--;
		int lst=lower_bound(p+1,p+m+1,ed)-p;
		lst--;
		if(lst<st){
//			cout<<5<<endl;
			return;
		}
		e[st-1].push_back(lst);
		deg[lst]++;
		od[x]=1;
	}
}		
void topo(){
	priority_queue<int,vector<int>, greater<int> > q;
	rep(i,0,m){
		if(deg[i]==0) q.push(i);
	}
	while(!q.empty()){
		int x=q.top();q.pop();
		if(x) ans[x]=max(ans[x],ans[x-1]);
		for(int i=0;i<e[x].size();i++){
			deg[e[x][i]]--;
			ans[e[x][i]]=max(ans[e[x][i]],ans[x]+1);
			if(deg[e[x][i]]==0) q.push(e[x][i]); 
		}
	}
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while(T--){
//		cout<<"Debug"<<endl;
		n=read(),m=read(),l=read(),V=read();
		rep(i,1,n){
			od[i]=0;
			d[i]=read(),v[i]=read(),a[i]=read();
		}
		deg[0]=0;e[0]=nll;ans[0]=0;
		rep(i,1,m){
			ans[i]=0;
			p[i]=read();
			deg[i]=0;
			e[i]=nll;
		}
		rep(i,1,n){
//			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			add(i);
		}
		int cnt=0;
		rep(i,1,n){
			if(od[i]){
				cnt++;
			}
		}
		cout<<cnt<<" ";
		int mx=0;
		topo();
		rep(i,0,m){
			mx=max(mx,ans[i]);
		}
		cout<<m-mx<<endl;
	}
	return 0;
}

