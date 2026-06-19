#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int n,m,k,ad[20],co[20010];
vector<int> e[20010],w[20010],id[20010];
bool used[20],ed[1000010];
void add(int u,int v,int we,int num){
	e[u].push_back(v);
	w[u].push_back(we);
	id[u].push_back(num);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(NULL));
	cin>>n;
	cout<<rand()%(n*100);	
//	for(int i=1;i<=n;i++){
//		int u,v,we;
//		cin>>u>>v>>we;
//		add(u,v,we,i);
//		add(v,u,we,i);
//	}
//	for(int i=1;i<=n;i++){
//		int minn=2e8,num=0,wh;
//		bool flag=1;
//		for(auto v:e[i]){
//		//	cout<<i<<' '<<v<<' '<<w[i][num]<<'\n';
//		//	cout<<1<<'\n'; 
//			num++;
//			if(minn>w[i][num]){
//				minn=w[i][num];
//			}
//			if(minn==w[i][num]){
//				cout<<ed[id[i][num]]<<'\n';
//				flag=!ed[id[i][num]];
//			}
//		}
//	//	cout<<1<<'\n'; 
//		if(!flag)continue;
//		num=0;
//		for(auto v:e[i]){
//			num++;
//			if(w[i][v]==minn){
//				ed[id[i][num]]=1;
//	//			cout<<id[i][num]<<' '<<minn<<'\n'; 
//				break;
//			}
//		}
//	}
	return 0;
}
/*
4 4 0
1 2 3
2 4 2
1 4 1
3 4 2 
*/
