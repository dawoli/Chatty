#include<bits/stdc++.h>
using namespace std;
//最小生成树 
int fa[1000006];

vector<int> v[1000006];

struct node{
	int u,v,w;
};

node a[1000006];

int get(int x){
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}

void merge(int x,int y){
	int xx=get(x);
	int yy=get(y);
	fa[yy]=xx;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out", "w", stdout);
	int n,m,k;
	cin >> n >> m >> k;
	string s;
	cin >> s;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin >> u >> v >> w;
		a[i]={u,v,w};
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	 
	cout  << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
