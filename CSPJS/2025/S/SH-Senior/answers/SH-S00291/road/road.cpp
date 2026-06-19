#include<bits/stdc++.h>
using namespace std;
const int N=10100;
vector<array<int,3>> e,ee;
int pp[N];
int n,m,k,maa;
int a[12][N],c[12],d[12];
int findp(int x){
	if(pp[x]!=x) pp[x]=findp(pp[x]);
	return pp[x];
}
long long rett=1ll<<60;
void solve(long long ext){
	long long ans=ext;
	for(int i=1;i<=n+k;i++) pp[i]=i;
	sort(e.begin(),e.end());
	for(auto vvv:e){
		int ww=vvv[0],uu=vvv[1],vv=vvv[2];
		int uu1=findp(uu);
		int vv1=findp(vv);
		if(uu1==vv1) continue;
		ee.push_back(vvv);
		ans+=ww;
		pp[uu1]=vv1;
	}
	rett=min(rett,ans); 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	ee.clear();
	for(int i=1;i<=m;i++){
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		e.push_back({ww,uu,vv});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		maa=max(c[i],maa);
		int mii=1;
		for(int j=1;j<=n;j++){
			int xx;cin>>xx;
			a[i][j]=xx;
			mii=min(mii,xx);
		}
		maa=max(maa,mii);
	}
	if(maa==0||k==0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e.push_back({a[i][j],j,n+i});
			}
		}
		solve(0);
		cout<<rett<<endl;
		cout<<flush;
		return 0;
	}
	solve(0);
//	for(auto vvv:ee) cout<<vvv[0]<<" "<<vvv[1]<<" "<<vvv[2]<<endl; 
	for(int i=1;i<(1<<k);i++){
		e.clear();
		for(auto vvv:ee) e.push_back(vvv);
		for(int j=1;j<=k;j++) d[j]=(i>>(j-1))&1;
		long long sum=0;
		for(int j=1;j<=k;j++){
			if(d[j]){
				sum+=c[j];
				for(int l=1;l<=n;l++){
					e.push_back({a[j][l],l,n+j});
				}
			}
		}
		solve(sum);
	}
	cout<<rett<<endl;
	cout<<flush;
	return 0;
}
