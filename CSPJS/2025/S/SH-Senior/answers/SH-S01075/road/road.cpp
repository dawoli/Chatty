#include<bits/stdc++.h>
using namespace std;

struct node{
	int bo[1000]={0};
	int eps[1000]; 
	int root;
}city[1000];
struct villiage{
	int bo[1000]={0};
	int build;
	int eps[1000];
	int root;
}xiang[10];
/*
struct node{
	int from;
	int to;
	int eps;
	int root;
}road[100000];
*/

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	
	cin>>n>>m>>k;
	
	int u,v,w;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		city[u].bo[v]=1;
		city[v].bo[u]=1;
		city[u].eps[v]=w;
		city[v].eps[u]=w;
		city[max(u,v)].root=min(u,v);
	}
	for(int j=0;j<k;j++){
		cin>>xiang[j].build;
		for(int i=0;i<n;i++){
			cin>>xiang[j].eps[i];
		}
	}
	
	//¼ÆËã£º£º
	int all;
	
	//chushihua
	
/*	
if(!k)
	for(int i=0;i>n;i++)
	{
		if(city[root]!=1)
	}
*/	 
	
} 
