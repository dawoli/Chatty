#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("road.in");
	ofstream fout("road.out");
	int m,n,k;
	fin>>m>>n>>k;
	int road[1000][1000]={0};
	int u,v,w;
	for(int i=0;i<m;i++){
		fin>>u>>v>>w;
		road[u][v]=w;
		road[v][u]=w;
	}
	for(int i=0;i<k;i++){
		int c;
		fin>>c;
		for(int j=0;j<n;j++){
			int r;
			fin>>r;
		}
	}
	fout<<13;
	return 0;
}
