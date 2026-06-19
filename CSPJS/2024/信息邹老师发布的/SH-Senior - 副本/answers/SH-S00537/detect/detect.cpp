#include<bits/stdc++.h>
using namespace std;
#define N 100007
int n,m,l,V;
int d[N],v[N],a[N];//位置，初速度 ，加速度
int p[N];
int c[N];
pair<int,int> pp[N];
int vis[N];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(c,0,sizeof(c));
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;++i){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;++i){
			cin>>p[i];
		}
		if(n<=20&&m<=20){
			for(int i=1;i<=n;++i){
				pp[i]={0,0};
			}
			int ans1=0;
			for(int i=1;i<=n;++i){
				if(a[i]==0){//不运动 
					if(v[i]>V){
						pp[i]={d[i],l+1};
					}
				}
				else if(a[i]<0){
					if(v[i]<=V) continue;
					int w=(V*V-v[i]*v[i])/(2*a[i]);
					if((V*V-v[i]*v[i])%(2*a[i])==0) --w;
					pp[i]={d[i],d[i]+w};
				}
				else{
					if(v[i]>V){
						pp[i]={d[i],l+1};
						continue;
					}
					int w=(V*V-v[i]*v[i])/(2*a[i])+1;
					pp[i]={d[i]+w,l+1};
				}
			}
			for(int i=1;i<=n;++i) vis[i]=0;
			//for(int i=1;i<=n;++i) cout<<pp[i].first<<' '<<pp[i].second<<'\n';
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					if(pp[i].first<=p[j]&&p[j]<=pp[i].second){
						vis[i]=1;
						break;
					}
				}
			}
			int ct=0;
			for(int i=1;i<=n;++i) ct+=vis[i];
			cout<<ct<<" ";
			int ans=0;
			for(int i=0;i<(1<<m);++i){
				for(int j=1;j<=n;++j) vis[j]=0;
				for(int j=0;j<m;++j){
					if(i>>j&1){
						for(int k=1;k<=n;++k){
							if(pp[k].first<=p[j+1]&&p[j+1]<=pp[k].second) vis[k]=1;
						}
					}
				}
				int cc=0;
				for(int j=1;j<=n;++j) cc+=vis[j];
				if(cc==ct){
					int g=i,one=0;
					while(g){
						g-=(g&(-g));
						++one;
					}
					ans=max(ans,m-one);
				}
			}
			cout<<ans<<'\n';
		} 
		else{
			int ans1=0;
			int mx=0;
			int ct=0;
			for(int i=1;i<=n;++i){
				if(v[i]>V){
					if(d[i]<=p[m]){
						++ct;
						mx=max(mx,d[i]);
					}
				}
			}
			if(ct==0) m++;
			cout<<ct<<' '<<m-1<<'\n';
		}
	}
} 
