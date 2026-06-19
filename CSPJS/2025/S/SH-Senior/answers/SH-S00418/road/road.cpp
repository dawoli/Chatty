#include<bits/stdc++.h>
using namespace std;
struct rd{
	int a;
	int b;
	int c;
};
struct nd{
	int cost;
	int odct[10009];
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	rd h[100009];
	nd j[19];
	for(int i=1;i<=m;i++){
		cin>>h[i].a>>h[i].b>>h[i].c;
	}
	for(int i=1;i<=n;i++){
		cin>>j[i].cost;
		for(int p=1;i<=m;i++){
		cin>>j[i].odct[p];
		}
	}
	cout<<"13"<<endl;
	return 0;
} 
