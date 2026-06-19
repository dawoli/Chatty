#include<bits/stdc++.h>
using namespace std;
constexpr int N=10001;
int n,m,k,tcst[11],tcnt[11];
struct EDGE{
	int fr,to;
	int cst;
	EDGE(int fr1,int to1,int w1):fr(fr1),to(to1),cst(w1){}
	bool operator<(EDGE other){ return (this->cst)<other.cst; }
};
long long ans[1025];
vector<EDGE> edges; // min tr
int father[N]; // togeth dict
int findf(int k){
	return (father[k]!=k)?(father[k]=findf(father[k])):k;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;++i){
		int fr1,to1,cst1;
		scanf("%d%d%d",&fr1,&to1,&cst1);
		edges.push_back(EDGE(fr1,to1,cst1));
	}
	const int tad=n+1;
	bool flag=true; //special A
	for(int i=0;i<k;++i){
		int cst1;
		scanf("%d",tcst+i);
		if(tcst[i]!=0) flag=false;
		for(int j=1;j<=n;++j){
			scanf("%d",&cst1);
			if(tcnt[i]==0 && cst1==0) tcnt[i]=j;
			edges.push_back(EDGE(tad+i,j,cst1));
		}
		if(tcnt[i]==0) flag=false;
	}
	if(flag){
		for(int i=0;i<edges.size();++i){
			if(edges[i].fr>=tad) edges[i].fr=tcnt[edges[i].fr-tad];
		}
		for(int i=1;i<=n;++i) father[i]=i;
		sort(edges.begin(),edges.end());
		int cnt=1,pos=0;
		long long ans=0;
		while(cnt<n){
			auto& e=edges[pos];
			if(e.fr==e.to){
				pos++;
				continue;
			}
			if(findf(e.fr)!=findf(e.to)){
				cnt++,pos++;
				father[findf(e.fr)]=findf(e.to);
				ans+=e.cst;
			}
			else pos++;
		}
		cout<<ans<<endl;
	}
	else{
		long long minn=-1;
		sort(edges.begin(),edges.end());
		for(int tpat=0;tpat<(1<<k);++tpat){
			long long ans=0;
			int tcnt=0,pat=tpat;
			for(int i=0;i<k;++i) {
				if(pat&1) tcnt++,ans+=tcst[i];
				pat>>=1;
			}
			if(ans>=minn && minn!=-1) break;
			for(int i=1;i<=n;++i) father[i]=i;
			int cnt=1,pos=0;
			while(cnt<n+tcnt && pos<edges.size()){
				auto& e=edges[pos];
				if(e.fr>=tad && (tpat&(1<<(e.fr-tad)))==0){
					pos++;
					continue;
				}
				if(e.fr==e.to){
					pos++;
					continue;
				}
				if(findf(e.fr)!=findf(e.to)){
					ans+=e.cst;
					if(ans>=minn && minn!=-1) break;
					cnt++,pos++;
					father[findf(e.fr)]=findf(e.to);
				}
				else pos++;
			}
			if(cnt==n+tcnt && (minn>ans || minn==-1)){
				minn=ans;
			}
		}
		cout<<minn<<endl;
	}
	return 0;
}
