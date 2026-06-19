#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
	bool operator < (const node & a)const{
		return y>a.y;
	}
};
struct node1{
	int x,y;
	bool h[11];
	bool operator < (const node & a)const{
		return y>a.y;
	}
};
int n,m,k;
vector<node>v[10010];
vector<long long>v1[11];
int f[10010];
bool u[10];
bool u1[10011];
void solve1(){
	priority_queue<node> pq;
	pq.push({1,0});
	long long ans=0;
	while(!pq.empty()){
		node a=pq.top();
		pq.pop();
		if(u1[a.x])continue;
		ans+=a.y;
		u1[a.x]=true;
		for(auto b:v[a.x]){
			pq.push({b.x,b.y});
		}
	}
	cout<<ans<<endl;
}
void solve2(){
	priority_queue<node> pq;
	pq.push({1,0});
	long long ans=0;
	while(!pq.empty()){
		node a=pq.top();
		pq.pop();
		if(u1[a.x])continue;
		ans+=a.y;
		u1[a.x]=true;
		for(auto b:v[a.x]){
			pq.push({b.x,b.y});
		}
	}
	for(int i=0;i<k;i++){
		ans=min(ans,v1[i][0]);
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=0;i<m;i++){
		int o,p,q;
		cin>>o>>p>>q;
		v[o].push_back({p,q});
		v[p].push_back({o,q});
	}
	int flag=1;
	for(int i=0;i<k;i++){
		int q;
		cin>>q;
		v1[i].push_back(q);
		for(int j=0;j<n;j++){
			int m;
			cin>>m;
			if(m!=0)flag=0;
			v1[i].push_back(m);
		}
	}
	if(k==0)solve1();
	if(flag==1) solve2();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
