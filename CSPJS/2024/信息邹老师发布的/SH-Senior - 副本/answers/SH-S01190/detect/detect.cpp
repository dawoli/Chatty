#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define Rep(i,l,r) for(int i=l;i>=r;--i)
using namespace std;
inline void chkmax(int&x,int y){if(x<y)x=y;}
const int N=2e5+5,M=1e6+5;
int T,n,m,L,V,l[N],r[N],p[N],g[M];
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	for(cin>>T;T--;){
		cin>>n>>m>>L>>V;
		rep(i,1,n){
			int d,v,a;
			cin>>d>>v>>a;
			if(a==0){
				if(v<=V)l[i]=1,r[i]=0;
				else l[i]=d,r[i]=L;
			}else if(a>0){
				if(v>V)l[i]=d,r[i]=L;
				else l[i]=min(L,d+(V*V-v*v)/(2*a))+1,r[i]=L;
			}else if(a<0){
				if(v<=V)l[i]=1,r[i]=0;
				else l[i]=d,r[i]=min(L,d+(v*v-V*V-1)/(2*abs(a)));
			}
		}
		memset(g,0,sizeof g);
		rep(i,1,m)cin>>p[i],g[p[i]]++;
		rep(i,1,L)g[i]+=g[i-1];
		int cnt=0;
		vector<pair<int,int>>vec;
		rep(i,1,n)if(g[l[i]-1]!=g[r[i]])cnt++,vec.push_back({r[i],l[i]});
		sort(vec.begin(),vec.end());
		int i=0,j=1,R=0,ans=0;
		while(i<vec.size()&&j<=m){
			while(i<vec.size()&&vec[i].second<=R)++i;
			if(i>=vec.size())break;
			while(j<=m&&p[j]<=vec[i].first)++j;
			ans++;R=p[j-1];
		}
		cout<<cnt<<' '<<m-ans<<endl;
	}
	return 0;
}
