#include<bits/stdc++.h>
using namespace std;
bool linked[10018];
int n,m,k,u,v,w,c,kcnt;
long long ans;
vector<pair<int,int>>e[10018];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
int rd(){
	int ans=0;
	char x=0;
	while(x<'0'||x>'9') x=getchar();
	do{
		ans*=10;
		ans+=x-'0';
		x=getchar();
	}while(x>='0'&&x<='9');
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	while(m--){
		u=rd(),v=rd(),w=rd();
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	} 
	while(k--){
		c=rd();
		kcnt++;
		if(c==0) for(int i=1;i<=n;i++){
			w=rd();
			e[n+kcnt].push_back({i,w});
			e[i].push_back({n+kcnt,w});
		}
		else if(k+kcnt<=5){
			
		}
	}
	linked[1]=1;
	for(int i=0;i<e[1].size();i++) q.push({e[1][i].second,e[1][i].first});
	while(!q.empty()){
		v=q.top().second,w=q.top().first;
		q.pop();
		if(linked[v]) continue;
		linked[v]=1;
		for(int i=0;i<e[v].size();i++) if(!linked[e[v][i].first]) q.push({e[v][i].second,e[v][i].first});
		ans+=w;
	}
	printf("%lld",ans);
	return 0;
}
