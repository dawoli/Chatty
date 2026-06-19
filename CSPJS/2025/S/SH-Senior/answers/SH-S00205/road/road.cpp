#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
#define pb push_back
long long n,m,k,fa[20009],co[20],ans,cnt;
struct awa{
	long long u,v,w;
}a[1000009];
vector<pair<long long,pair<long long,long long> > >e[20];
long long cmp(awa a,awa b){
	return a.w<b.w;
}
long long find(long long x){
	if(x==fa[x]) return fa[x];
	return fa[x]=find(fa[x]);
}
void merge(long long x,long long y){
	long long xx=find(x),yy=find(y);
	fa[xx]=yy;
	return ;
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>co[i];
		for(int j=1;j<=n;j++){
			long long P;
			cin>>P;
			e[i].pb({P,{i+n,j}});
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(cnt==n-1) break;
		if(find(a[i].v)==find(a[i].u)) continue;
		else cnt++,merge(a[i].v,a[i].u),ans+=a[i].w,e[0].pb({a[i].w,{a[i].v,a[i].u}});
 	}
 	//return ;

 	for(int i=0;i<(1<<k);i++){
 		long long anss=0,cnt=0,kcnt=0;
 		priority_queue<pair<long long,pair<long long,long long> > ,vector<pair<long long,pair<long long,long long> > > ,greater<pair<long long,pair<long long,long long> > > >q[19];
 		for(int j=1;j<=n+k;j++) fa[j]=j;
 		for(int i=0;i<n-1;i++) q[0].push(e[0][i]);
 		for(int j=1;j<=k;j++){
 			if(i&(1<<(j-1))){
 				//return;
 				//cout<<j<<' ';
 				kcnt++,anss+=co[j];
 				//return ;
	 			for(int l=0;l<n;l++){
	 				q[j].push(e[j][l]);
	 				//return ;
	 			}
 			}
 			//cout<<kcnt<<'\n';
 		}
 		//return ;
 		long long ppp=0;
 		//cout<<q[1].size();
 		//for(int i=0;i<4;i++) cout<<e[1][i].second.second<<' '<<e[1][i].second.first<<'\n';
 		//if(i==1) return;
 		//if(i==1)return ;
		while(1){

			//ppp++;

			if(n+kcnt-1==cnt) break;
			long long id;
			pair<long long,pair<long long,long long> >kkk;
			kkk={1e18,{0,0}};
			//if(i==1) return ;
			for(int j=0;j<=k;j++){
				//if(ppp==1&&j==1) return ;
				if(q[j].empty()) continue;
				//if(ppp==1&&j==1) return ;
				//if(ppp==1&&j==1) cout<<find(q[j].top().second.first)<<' '<<find(q[j].top().second.second)<<'\n';
				//if(ppp==1&&j==1) cout<<q[j].top().second.first<<' '<<q[j].top().second.second<<'\n';
				//if(ppp==1&&j==1) return ;
				while(!q[j].empty()){
					if(find(q[j].top().second.first)==find(q[j].top().second.second)){
						//if(ppp==1&&j==1) return ;
						//cout<<find(q[j].top().second.first)<<' '<<find(q[j].top().second.second)<<'\n';
						//cout<<q[j].top().second.first<<' '<<q[j].top().second.second<<'\n';
						q[j].pop();
						ppp++;
						//if(ppp==1&&j==1) return ;
						//if(ppp==1) return ;
					}else if(q[j].top().first<=kkk.first){
						//if(ppp==1&&j==1) return ;
						kkk=q[j].top();
						id=j;
						//if(j==0&&i==1) return ;
						//cout<<"!!!";
						break;
					}else{
						break;
					}
				}
				//if(ppp==1&&j==1) return ;
				//if(i==1) break;
			}
			//cout<<kkk.second.first<<' '<<kkk.second.second<<' '<<kkk.first<<'\n';
			cnt++,merge(kkk.second.first,kkk.second.second),anss+=kkk.first,q[id].pop();
			//if(i==1&&ppp==3) return ;
			//if(ppp>=15) return ;
	 	}
	 	//cout<<anss<<'\n';
	 	ans=min(anss,ans);
	 	//if(i==1) return ;
 		//return ;
 	}
 	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long T=1;//cin>>T;
	while(T--) solve(); 
}
//subscribe tasho11y(uid=1385732) in bilibili(in luogu)!!!
//at 3:40