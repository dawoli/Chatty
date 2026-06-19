#include<bits/stdc++.h>
using  namespace std;
struct e{
	int p,v;
};
vector<e>q[10005];
bool b[10005];
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int m,n,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e e1;
		e1.p=z;e1.v=y;
		q[x].push_back(e1);
		e e2;
		e2.p=z;e2.v=x;
		q[x].push_back(e2);
	}
	for(int j=1;j<=k;j++){
		int f;
		cin>>f;
		for(int i=1;i<=m;i++){
			cin>>f;
			e e1;
			e1.p=f;e1.v=i;
			q[m+j].push_back(e1);
			
		}
	}
	return 0;
} 
