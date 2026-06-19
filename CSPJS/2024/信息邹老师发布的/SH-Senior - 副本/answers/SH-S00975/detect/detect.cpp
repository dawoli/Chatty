#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n, m, l, r, res, ans;
double len, lim;
double p[N];
stack<int> vis, vis2;
struct car{
	double d, v, a;
	double s, x, l, r;
	bool operator <(const car& rhs) const
	{return l==rhs.l?r<rhs.r:l<rhs.l;}
}c[N];
void init(){
	for(int i=1;i<=n;i++){
		if(c[i].a>=0.0) c[i].s=len;
		else c[i].s=min(c[i].d+(c[i].v*c[i].v)/(2.0*(-c[i].a)),len);
		if(c[i].a==0){
			if(c[i].v>lim){
				c[i].l=c[i].d;
				c[i].r=len;
			}
		}
		else{
			c[i].x=(lim*lim-c[i].v*c[i].v)/(2.0*c[i].a);
			if(c[i].a>0.0){
				if(c[i].x+c[i].d>=len) c[i].l=c[i].r=-1.0;
				else{
					c[i].l=c[i].d+max(c[i].x,0.0);
					c[i].r=len; 
				}
			}
			else if(c[i].a<0.0){
				if(c[i].v<=lim) c[i].l=c[i].r=-1.0;
				else{
					c[i].l=c[i].d;
					c[i].r=min(c[i].d+c[i].x,c[i].s);
				}
			}
		}
	}
}
bool visi[N];
void dfs(int now, int num){
	if(now>m){
		int cov=0;
		memset(visi,0,sizeof visi);
		while(!vis.empty()){
			int y=vis.top();vis.pop();vis2.push(y);
			for(int i=1;i<=n;i++){
				if(visi[i]) continue; 
				if(p[y]>=c[i].l&&p[y]<=c[i].r){
					++cov;
					visi[i]=true;
				}
			}
		}
		while(!vis2.empty()){
			int y=vis2.top();vis2.pop();
			vis.push(y);
		}
		if(cov==res) ans=max(ans,m-num);
		return;
	}
	if(m-num<=ans) return;
	for(int i=now;i<=m;i++){
		vis.push(i);
		dfs(i+1,num+1);
		vis.pop();
		dfs(i+1,num);
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>len>>lim;
		for(int i=1;i<=n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
		for(int i=1;i<=m;i++) cin>>p[i];
		init();sort(c+1,c+n+1);
		res=0;
		for(int i=1;i<=n;i++){
//			cout<<"car:"<<i<<' '<<c[i].l<<' '<<c[i].r<<'\n';
			for(int j=1;j<=m;j++){
				if(p[j]>=c[i].l&&p[j]<=c[i].r){
					++res;
					break;
				}
			}
		}
//		cout<<"pos:";
//		for(int i=1;i<=m;i++) cout<<p[i]<<' ';cout<<'\n';
		ans=-1;
		cout<<res<<' ';
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
