#include<bits/stdc++.h>
using namespace std;	
int n,m,k;
struct road{
	int u,v,c;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	vector<road> vec;
	road x;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		x.u=a;
		x.v=b;
		x.c=c;
		vec.push_back(x);
	}
	int cs,ttt;
	return 0;
} 
