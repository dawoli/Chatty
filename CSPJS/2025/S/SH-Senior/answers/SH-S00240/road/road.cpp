#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct edge{
	int x,y,z;
	void read(){
		cin>>x>>y>>z;
	}
	void test(){
		cout<<x<<' '<<y<<' '<<z<<endl;
	}
} graph[1000006];
vector<edge> vec;
bool cmp(edge e1,edge e2){
	return e1.z<e2.z;
}
int fa[10005];
int find(int x){
	if(x==fa[x]) return x;
	return find(fa[x]);
} 
int viliage[10][10005];
int Krustal(){
	int ans=0;
	for(int i=1;i<=m;i++){
		int x=graph[i].x,y=graph[i].y,z=graph[i].z;
		int a=find(x),b=find(y); 
		if(a==b) continue;
		else fa[a]=b;
		ans+=z;
		vec.push_back(graph[i]);
		if(vec.size()==n-1){
			break;
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		graph[i].read();
	} 
	sort(graph+1,graph+m+1,cmp);
	int tmp=Krustal();
	cout<<tmp<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
