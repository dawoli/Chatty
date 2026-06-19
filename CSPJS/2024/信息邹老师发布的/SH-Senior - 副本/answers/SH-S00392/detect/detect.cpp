#include<bits/stdc++.h>
#define ERR 0.0000001
using namespace std;
int t,n,m,l,w,p[100001],lb[100001],rb[100001],cs;
pair<int,int> ers[100001];
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	return a.second<b.second;
}
set<pair<int,int> > g[20];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d%d%d%d",&n,&m,&l,&w);
		for(int i=1;i<=n;i++){
			int d,v,a;
			scanf("%d%d%d",&d,&v,&a);
			if(a>0){
				if(v>w) lb[i]=d;
				else lb[i]=min(int((w-v)*(w+v)/(2.0*a)+ERR)+d+1,l+1);
				rb[i]=l+1;
			}
			if(a==0){
				if(v>w) lb[i]=d;
				else lb[i]=l+1;
				rb[i]=l+1;
			}
			if(a<0){
				if(v>w){
					lb[i]=d;
					rb[i]=min(int((v-w)*(w+v)/(-2.0*a)-ERR)+d+1,l+1);
				}
				else lb[i]=rb[i]=l+1;
			}
		}
		for(int i=1;i<=m;i++) scanf("%d",p+i);
		sort(p+1,p+m+1);
		p[m+1]=1e9;
		int cnt=0,eri=0;
		for(int i=1;i<=n;i++){
			int nl=1,nr=m;
			while(nl<=nr){
				int nmid=(nl+nr)/2;
				if(p[nmid]>=lb[i]) nr=nmid-1;
				else nl=nmid+1;
			}
			if(rb[i]>p[nl]){
				cnt++;
				ers[cs].second=nl;
				nl=1;
				nr=m;
				while(nl<=nr){
					int nmid=(nl+nr)/2;
					if(p[nmid]>=rb[i]) nr=nmid-1;
					else nl=nmid+1;
				}
				ers[cs].first=nr;
				g[t].insert(ers[cs++]);
			}
		}
		printf("%d ",cnt);
		sort(ers,ers+cs,cmp);
		cnt=0;
		int lsz=1e9;
		while(!g[t].empty()){
			if(g[t].size()==lsz) break;
			lsz=g[t].size();
			int toe=g[t].begin()->first;
			while(ers[eri].second<=toe&&eri<=cs) g[t].erase(ers[eri++]);
			cnt++;
		}
		printf("%d\n",m-cnt);
	}
	return 0;
}
