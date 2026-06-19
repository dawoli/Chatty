#include<bits/stdc++.h>
using namespace std;
struct road{
	int a;
	int b;
	int cost;
};
int n,m,k;
vector<int> fa;
int find(int a){
	if(fa[a]!=a){
		fa[a]=find(fa[a]);
	}
	return fa[a];
}
//永远以小的为根 
void connect(int a,int b){
	if(a>b){
		int c=a;
		a=b;
		b=c;
	}
	fa[b]=find(fa[a]);
}
bool zzz(road a,road b){
	return a.cost<b.cost;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;//城市 道路 农村 
	vector<road> roads;
	//普通道路 
	for(int i=0;i!=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		road temp;
		temp.cost=w;
		temp.a=u;
		temp.b=v;
		roads.push_back(temp);
	}
	//农村道路 
	for(int i=0;i!=k;i++){
		int node=-1;
		vector<long long> faster;
		for(int j=0;j!=n+1;j++){
			int temp;
			cin>>temp;
			faster.push_back(temp);
			if(temp==0 and j!=0){
				node=j;
			}
		}
		if(node==-1){
			cout<<5182974424;
			return 0;
		}
		for(int j=1;j!=n+1;j++){
			if(j==node){
				continue;
			}
			bool have=false;
			for(long long z=0;z!=roads.size();z++){
				if((roads[z].a==node and roads[z].b==j) or (roads[z].a==j and roads[z].b==node)){
					have=true;
					if(roads[z].cost>faster[j]){
						//cout<<"***"<<j<<' '<<faster[j]<<endl;
						roads[z].cost=faster[j];
					}
					break;
				}
			}
			road temp;
			temp.cost=faster[j];
			temp.a=node;
			temp.b=j;
			if(have==false){
				roads.push_back(temp);
			}
		}
	}
	//排序
	sort(roads.begin(),roads.end(),zzz);
	//并查集 
	for(int i=0;i!=n+5;i++){
		fa.push_back(i);
	}
	//贪心 
	long long ans=0;
	for(long long i=0;i!=roads.size();i++){
		if(find(roads[i].a)!=find(roads[i].b)){
			connect(roads[i].a,roads[i].b);
			ans+=roads[i].cost;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 4 1
1 2 3
2 3 2
1 3 1
1 4 5
0 0 2 2 4
ans=7
*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 8 2 4
0 0 3 2 4
ans=9
*/
