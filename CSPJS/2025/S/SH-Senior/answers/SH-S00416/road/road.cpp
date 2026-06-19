#include<iostream>
using namespace std;
struct rd{
	int r;
	int l;
	int v;
}a[1000005];
int b[10005][15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].r>>a[i].l>>a[i].v;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			cin>>b[i][j];
		}
	}
	return 0;
}
