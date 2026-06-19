#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct info{
	int length;
	int *dictionary;
};
int maxrounds;
bool comparison(pair<int,int> a,pair<int,int> b){
	return a.first<b.first;
}
void search(int round,int point,int index,int preid,pair<int,int> tasklist[],bool ability[],vector<pair<int,int> > graph[]){
	if(round>maxrounds)return;
	while(tasklist[index].first==round){
		if(tasklist[index].second==point)ability[index]=true;
		index++;
	}
	for(int i=0;i<graph[point].size();i++){
		if(preid==graph[point][i].first)continue;
		else search(round+1,graph[point][i].second,index,graph[point][i].first,tasklist,ability,graph);
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int inquiry;
	cin>>inquiry;
	int m;
	while(inquiry--){
		int types,limit,tasks;
		cin>>types>>limit>>tasks;
		struct info data[types];
		m=0;
		for(int i=0;i<types;i++){
			cin>>data[i].length;
			int tmp[data[i].length];
			for(int j=0;j<data[i].length;j++){
				cin>>tmp[j];
				m=max(m,tmp[j]);
			}
			data[i].dictionary=tmp;
		}
		vector<pair<int,int> > graph[m+1];
		for(int i=0;i<types;i++){
			for(int start=0;start<data[i].length-1;start++){
				for(int end=start+1;end<data[i].length;end++){
					graph[data[i].dictionary[start]].push_back(make_pair(i,data[i].dictionary[end]));
				}
			}
		}
		pair<int,int> tasklist[tasks];
		bool ability[tasks];
		maxrounds=0;
		for(int i=0;i<tasks;i++){
			cin>>tasklist[i].first>>tasklist[i].second;
			maxrounds=max(maxrounds,tasklist[i].first);
			ability[i]=false;
		}
		sort(tasklist,tasklist+tasks,comparison);
		search(0,1,0,-1,tasklist,ability,graph);
		for(int i=0;i<tasks;i++){
			cout<<ability[i]<<endl;
		}
	}
	return 0;
}

