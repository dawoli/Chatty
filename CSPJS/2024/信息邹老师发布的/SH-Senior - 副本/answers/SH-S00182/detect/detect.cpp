#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#define int long long
int t,n,m,l,V,d[3005],v[3005],a[3005],p[3005],ans1=0;
bool outlimit[3005];
std::vector<int> keep[3005]; 
int best=1e9;
bool used[3005];
bool got[3005];
void solve1(int i,int tot){
	if(i>m){
	//	std::cout<<"k";
		for(int j=1;j<=n;j++){
			got[j]=false;
		}
		for(int j=1;j<=m;j++){
			if(used[j]){
			//	std::cout<<j<<" ";
				for(int x:keep[j]){
					got[x]=true;
				//	std::cout<<x<<" ";
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(!got[j] and outlimit[j]) return;
		}
		best=std::min(best,tot);
		return;
	}
	used[i]=true;
	solve1(i+1,tot+1);
	used[i]=false;
	solve1(i+1,tot);
}
void check(int i,int j){
	int dis=p[j]-d[i];
	if(dis<0) {
		return;
	}
	if(a[i]==0){
		if(v[i]>V){
			outlimit[i]=true;
			keep[j].push_back(i);
		}
		return;
	}
	else{
		long long now=v[i]*v[i]+2*a[i]*dis;
		if(now<0) return;
		long long present=sqrt(now);
		if(present*present!=now){
			present++;
		}
		if(present>V){
			outlimit[i]=true;
			keep[j].push_back(i);
		}
		return;
	}
}
void solve(){
	std::cin>>n>>m>>l>>V;
	for(int i=1;i<=m;i++) keep[i].clear();
	ans1=0;
	memset(used,0,sizeof(used));
	memset(got,0,sizeof(got));
	memset(outlimit,0,sizeof(outlimit));
	best=1e9;
	for(int i=1;i<=n;i++){
		std::cin>>d[i]>>v[i]>>a[i];
	}
	for(int i=1;i<=m;i++){
		std::cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			check(i,j);
		}
	}
/*	std::cout<<"\n";
	for(int i=1;i<=n;i++){
		if(outlimit[i]) std::cout<<i<<" ";
	}
	std::cout<<"\n";
	for(int i=1;i<=m;i++){
		std::cout<<i<<" ";
		for(int x:keep[i]) {
			std::cout<<x<<" ";
		}
		std::cout<<"\n";
	}
	*/
	for(int i=1;i<=n;i++){
		if(outlimit[i]) ans1++;
	}
	solve1(1,0);
	std::cout<<ans1<<" "<<m-best<<"\n";
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	std::cin>>t;
	while(t--){
		solve();
	} 
	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/


