#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,sum;
bool flag=0;
int a[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		sum+=w;
	}
	if(k==0){
		printf("%d",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
