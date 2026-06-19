#include<bits/stdc++.h>
const int N=11111,M=1234567;
const long long INF=1e16;
using std::cin;
using std::cout;
struct Edge{
	int u,v,w;
	bool operator<(const Edge&x)const{
		return w!=x.w?w<x.w:(u!=x.u?u<x.u:v<x.v);
	}
}e[M];
int nE;
/**Hope the programmes run well**/
int id[N];
int rt(int u){
	return id[u]==u?u:id[u]=rt(id[u]);
}
/**Hope the programmes run well**/
int n,m,k;
bool flgA=1;
long long ans=INF,c[20];
/**Hope the programmes run well**/
void solveA(){
	for(int i=1;i<=n+k;i++)id[i]=i;
	int cnt=0,mxM=n+k-1,i=0,ru,rv;ans=0;
	do{
		i++;
		ru=rt(e[i].u),rv=rt(e[i].v);
		if(ru!=rv){
			cnt++;
			id[ru]=rv;
			ans+=e[i].w;
		}
	}while(cnt<mxM);
}
void solve(){
	int nPtr=1<<k,cnt,mxM,i,ru,rv;
	long long res;
	for(int p=0;p<nPtr;p++){
		mxM=n-1,res=0;
		for(int ii=1;ii<=k;ii++)
			if(p&(1<<ii-1))
				mxM++,res+=c[ii];
		for(int ii=1;ii<=n+k;ii++)id[ii]=ii;
		i=0,cnt=0;
		do{
			i++;
			if(e[i].u>n&& !(p&(1<<e[i].u-n-1))||
				e[i].v>n&& !(p&(1<<e[i].v-n-1)))continue;
			ru=rt(e[i].u),rv=rt(e[i].v);
			if(ru!=rv){
				cnt++;
				id[ru]=rv;
				res+=e[i].w;
			}
		}while(cnt<mxM);
		ans=std::min(ans,res);
	}
}
/**Hope the programmes run well**/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);std::ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[++nE]={u,v,w};
	}
	for(int i=1,v,w;i<=k;i++){
		v=1;
		cin>>c[i];
		if(c[i])flgA=0;
		if(flgA){
			flgA=0;
			while(v<=n){
				cin>>w;
				e[++nE]={n+i,v,w};
				if(!w)flgA=1;
				v++;
			}
		}else{
			while(v<=n){
				cin>>w;
				e[++nE]={n+i,v,w};
				v++;
			}
		}
	}
	std::sort(e+1,e+nE+1);
	if(flgA)solveA();
	else solve();
	cout<<ans;
	return 0;
}
