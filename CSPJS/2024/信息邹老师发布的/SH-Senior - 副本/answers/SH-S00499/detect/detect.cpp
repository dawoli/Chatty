#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define up(l,r,i) for(int i=(l);i<=(r);++i)

constexpr int N=1e5+7;
constexpr double eps=1e-6;

int n,m,L,V;
int d[N],v[N],a[N],p[N];
double l[N],r[N];

double getd(double v0,double a,double t){
	return v0*t+0.5*a*t*t;
}

struct segment{
	int left,right;
	friend bool operator <(segment a,segment b){
		if(a.right!=b.right)return a.right<b.right;
		return a.left<b.left;
	}
};

vector<segment> seg;

void solve(){
	cin>>n>>m>>L>>V;
	seg.clear();
	int ans1=0,ans2=0;
	up(1,n,i){
		cin>>d[i]>>v[i]>>a[i];
	}
	up(1,m,i)cin>>p[i];
	up(1,n,i){
		if(a[i]==0){
			if(v[i]>V)l[i]=d[i],r[i]=L;
			else l[i]=r[i]=-1;
		}
		else if(a[i]>0){
			if(v[i]>V)l[i]=d[i],r[i]=L;
			else{
				double t=(double)(V-v[i])/a[i];
				double _d=getd(v[i],a[i],t);
				_d+=d[i];
				if(_d<=L)l[i]=_d+eps,r[i]=L+eps;
				else l[i]=r[i]=-1;
			}
		}
		else{//a[i]<0
			if(v[i]<=V)l[i]=r[i]=-1;
			else{
				double t=(double)(V-v[i])/a[i];
				l[i]=d[i],r[i]=getd(v[i],a[i],t)+l[i]-eps;
			}
		}
		//cout<<fixed<<setprecision(8)<<l[i]<<' '<<r[i]<<' ';
		int _l=lower_bound(p+1,p+m+1,l[i])-p;
		int _r=upper_bound(p+1,p+m+1,r[i])-p-1;
		//cout<<_l<<' '<<_r<<'\n';
		if(_l<=_r){
			++ans1;
			seg.push_back({_l,_r});
		}
	}
	sort(seg.begin(),seg.end());
	int cnt=0;
	for(segment x:seg){
		//cout<<x.left<<' '<<x.right<<'\n';
		if(x.left>cnt)++ans2,cnt=x.right;
	}
	cout<<ans1<<' '<<m-ans2<<'\n';
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;cin>>tc;
	while(tc--){
		solve();
	}
	return 0;
}
