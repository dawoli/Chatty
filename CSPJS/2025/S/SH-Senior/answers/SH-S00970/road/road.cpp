#include <bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,price;
}road[1000002];
int updcost[10],vroad[11][10001];
bool upd[10],cond[10002];
int v2c(int a,int b,int k){
	int tot,tk;
	for(int i=0;i<k;i++){
		int temp=vroad[k][a]+vroad[k][b];
		if(!upd[i]) temp=temp+updcost[i];
		if(tot>temp){
			tot=temp;
			tk=i;
		}
	}
	return tot,tk;
};
bool cmp(edge x,edge y){
	return x.price<y.price;
}
int cd2[10002]={},blocksize[10002]={},block[10002][10002]={};
int n,m,k,ans=0,cd=0,fn=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	//cout<<m;
	for (int i=0;i<m;i++){
		cin>>road[i].from>>road[i].to>>road[i].price;
		//cout<<road[i].price;
	}
	for(int i=0;i<k;i++){
		//cout<<updcost[i];
		for(int j=0;j<n;j++){
			cin>>vroad[k][j];
			//vroad[k][j].from=k;vroad[k][j].to=j;
		}
	}
	for(int i=0;i<n;i++) cd2[i]=i;
	sort(road,road+m,cmp);
	fn=(1+n)*n/2;
	cd=cd+road[0].from;
	for(int z=0;z<m;z++){
		int from,to;
		from = road[z].from;
		to = road[z].to;
		int temp,tempk=v2c(from,to,k);
		//cout<<"1";
		if(cd2[to]!=cd2[from]){
			if(road[z].price>temp){
				ans=ans+temp;
				upd[tempk]=true;
				//cout<<ans;
			}
			else{ans=ans+road[z].price;cout<<ans;}
			if(cd2[from]!=from) from=cd2[from];
				block[from][blocksize[from]++]=to;
				if(cd2[to]!=to){
					if(cd2[from]==from){
						for(int o=0;o<blocksize[to];o++){
							block[from][blocksize[from]++]=block[cd2[to]][o];
							cd2[block[cd2[to]][o]]=from;
						}
						//cout<<"1";
					}
					else{
						for(int o=0;o<blocksize[from];o++){
							block[cd2[from]][blocksize[cd2[from]]++]=block[cd2[to]][o];
							cd2[block[cd2[to]][o]]=cd2[from];
						}
					}
				}
				else{
					if(blocksize[to]>0){
					for(int o=0;o<blocksize[to];o++){
							block[cd2[from]][blocksize[cd2[from]]++]=block[to][o];
							cd2[block[to][o]]=cd2[from];
						}
					}
					else{
					cd2[to]=from;
					//cout<<"1";
					}
				}
			cd=cd+to;
			if(cd==fn){
			cout<<ans;
			break;
		}
		}
	}
	return 0;
}
