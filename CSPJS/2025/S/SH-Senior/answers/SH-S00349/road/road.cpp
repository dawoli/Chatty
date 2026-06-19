#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
};
struct yyy{
	int fei;
	int q[1000000]={};
}y[1000000];
int main(){
	freopen("road.in","r",stdin);
	int n,m,k;
	cin>>n>>m>>k;
	node a[1000000]={};
	for(int i=0;i>m;i++){
		cin>>a.u>>a.v>>a.w;
	}
	for(int i=0;i<k;i++){
		cin>>y[i].fei;
		for(int j=0;j<n;j++){
			cin<<y[i].q[j];
		}
	}
	
	freopen("road.out","w",stdout);
	return 0;
}
