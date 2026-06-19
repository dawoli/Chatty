#include <bits/stdc++.h>
using namespace std;
//DEUS BEAT AZERTIAM
struct link{
	int pater;
	int price;
	bool on;
};
struct situation{
	int voidcash;
	int nodes;
	int price;
	vector<vector<pair<int,int> > > lktbl;
};
int ssl(int nodes,
	vector<vector<pair<int,int> > > lktbl){
	vector<link> nodessl;
	nodessl.resize(nodes);
	for(int i=0;i<nodes;i++)nodessl[i].on=false;
	nodessl[0]={-1,0,true};
	queue<int> quick;
	quick.push(0);
	while(!quick.empty()){
		int thiz=quick.front();
		for(auto& e:lktbl[thiz]){
			if(!nodessl[e.first].on){
				nodessl[e.first]={thiz,e.second,true};
				quick.push(e.first);
			}else{
				if(nodessl[e.first].price>e.second){
					bool flag=true;
					for(int i=nodessl[thiz].pater;i!=-1;i=nodessl[i].pater){
						if(i==e.first)
						flag=false;
					}
					if(flag){
					nodessl[e.first].price=e.second;
					nodessl[e.first].pater=thiz;
					}
				}
			}
		}
		quick.pop();
	}
	int total=0;
	for(auto& eq:nodessl){
		total+=eq.price;
	}
	return total;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int nodes,roads,optionales;
	cin>>nodes>>roads>>optionales;
	vector<vector<pair<int,int> > > lktbl;
	lktbl.resize(nodes);
	for(int i=0;i<roads;i++){
		int a,b,c;
		cin>>a>>b>>c;a--;b--;
		lktbl[b].push_back(make_pair(a,c));
		lktbl[a].push_back(make_pair(b,c));
	}
	cout<<ssl(nodes,lktbl)<<endl;
	return 0;
	vector<situation> sits;
	sits.push_back({0,nodes,ssl(nodes,lktbl),lktbl});
	for(int i=0;i<optionales;i++){
		situation optimum=sits[0];
		for(auto& est:sits){
		int build;
		cin>>build;
		vector<vector<pair<int,int> > > lktbl1=est.lktbl;
		lktbl1.push_back(vector<pair<int,int>>());
		for(int j=0;j<nodes;j++){
			int prize;
			cin>>prize;
			lktbl1[nodes].push_back(make_pair(j,prize));
			lktbl1[j].push_back(make_pair(nodes,prize));
		}
		int nova=ssl(est.nodes+1,lktbl1);
		if(nova+build>optimum.price+optimum.voidcash){
			optimum={build+est.voidcash,est.nodes+1,nova,lktbl1};
		}
		}
		sits.push_back(optimum);
	}
	int totl=0;
	for(auto& es:sits){
		totl=max(totl,es.price+es.voidcash);
	}
}
