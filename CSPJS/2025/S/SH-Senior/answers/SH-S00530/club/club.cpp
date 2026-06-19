#include<bits/stdc++.h>
#define mp(x,y,z) make_pair(x,make_pair(y,z))
#define piii pair<int,pair<int,int> > 
using namespace std;
int n,a[100010][4],sm;
priority_queue<piii,vector<piii>,greater<piii> > pq[4];
void cl(){
	while(!pq[1].empty())	pq[1].pop();
	while(!pq[2].empty())	pq[2].pop();
	while(!pq[3].empty())	pq[3].pop();
	for(int i=1;i<=100000;++i)
		a[i][1]=a[i][2]=a[i][3]=0;
	sm=0;
}
int solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int maxn=0;
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		maxn=max(max(a[i][1],a[i][2]),a[i][3]);
		if(maxn==a[i][1]){
			sm+=maxn;
			int k=max(a[i][2],a[i][3]);
			if(k==a[i][2])	pq[1].push(mp(maxn-k,i,2));
			else			pq[1].push(mp(maxn-k,i,3));
		}
		else if(maxn==a[i][2]){
			sm+=maxn;
			int k=max(a[i][1],a[i][3]);
			if(k==a[i][1])	pq[2].push(mp(maxn-k,i,1));
			else			pq[2].push(mp(maxn-k,i,3));
		}
		else{
			sm+=maxn;
			int k=max(a[i][1],a[i][2]);
			if(k==a[i][1])	pq[3].push(mp(maxn-k,i,1));
			else			pq[3].push(mp(maxn-k,i,2));
		}
	}
	while(!(pq[1].size()<=n/2&&pq[2].size()<=n/2&&pq[3].size()<=n/2)){
		while(pq[1].size()>n/2){
			piii x=pq[1].top(); pq[1].pop();
			sm-=x.first;
			pq[x.second.second].push(mp(a[x.second.first][x.second.second]-a[x.second.first][6-1-x.second.second],x.second.first,6-1-x.second.second));
		}
		while(pq[2].size()>n/2){
			piii x=pq[2].top(); pq[2].pop();
			sm-=x.first;
			pq[x.second.second].push(mp(a[x.second.first][x.second.second]-a[x.second.first][6-3-x.second.second],x.second.first,6-2-x.second.second));
		}
		while(pq[3].size()>n/2){
			piii x=pq[3].top(); pq[3].pop();
			sm-=x.first;
			pq[x.second.second].push(mp(a[x.second.first][x.second.second]-a[x.second.first][6-3-x.second.second],x.second.first,6-3-x.second.second));
		}
	}
	printf("%d\n",sm);
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		cl();
		solve();
	}
}
