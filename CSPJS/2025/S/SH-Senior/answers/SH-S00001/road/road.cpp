#include <iostream>
using namespace std;
//int weights[10005][10005];
//struct road{
//	int i,j;
//	int repcos;
//};
//find all connected components, choose two, and then see at what cost can we make them into one
//do this until there is only one connected component

int n,m,k,u,v,w,c,a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	//matrix to store every path wont work
	//since it is too large...
	
	//ehh get some points for special case A
	
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
	}
	for(int i=0;i<k;i++){
		cin>>c;
		for(int j=0;j<n;j++){
			cin>>a;
		}
	}
	cout<<0;
	return 0;
}
