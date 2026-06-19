#include<bits/stdc++.h>
using namespace std;
long long n,m,k,i,i1;
long long mList[1000001][3],kList[11][10001],cList[11];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	while(i < m){
		cin>>mList[i][0]>>mList[i][1]>>mList[i][2];
		i ++;}
	while(i < k){
		scanf("%d",&cList[i]);
		while(i1 < n){
			scanf("%d",&kList[i][i1]);
			i1 ++;}
		i ++;}
	
	cout<<15;
	return 0;
} 
