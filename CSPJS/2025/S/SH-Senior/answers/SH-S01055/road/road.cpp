#include <bits/stdc++.h>
using namespace std;
int n,m,k,road[1000005][2], croad[12][1000005],i,j,fn=0,road2[1000005],x,y,z,w,flg;
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (i = 0;i<m;i++){
		cin>>road[i][0]>>road[i][1]>>road2[i];
	}
	for(i=0;i<k;i++){
		for(j =0;j<n;j++){
			cin>>croad[i][j];}}
	int cnt = 0;
	//zhiquAtelishiyishi
	sort(road2, road2+m);
	for (i =0;i<n-1;i++){
		fn += road2[i];
	}
	cout<<fn;
	fclose(stdin);fclose(stdout);
}
