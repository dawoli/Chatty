#include<bits/stdc++.h>
using namespace std;

const int maxn=1001,deltaRow[]={0,1,0,-1},deltaColumn[]={1,0,-1,0};
int T,n,m,k,x,y,d;
bool forest[maxn][maxn],visited[maxn][maxn];

void calc(){
	long long cnt=1;
	for(int i=0; i<k; i++){
		auto newrow=x+deltaRow[d],newcolumn=y+deltaColumn[d];
		if (1<=newrow and newrow<=n and 1<=newcolumn and newcolumn<=m and not forest[newrow][newcolumn]){
			x=newrow;
			y=newcolumn;
			if (visited[x][y]) continue;
			cnt++;
			visited[x][y]=true;
			continue;
		}
		d=(d+1)%4;
	}
	cout<<cnt<<'\n';
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for (int i=0; i<T; i++){
		cin>>n>>m>>k>>x>>y>>d;
		memset(forest,false,sizeof(forest));
		memset(visited,false,sizeof(visited));
		visited[x][y]=true;
		for (int row=1; row<=n; row++){
			for (int column=1; column<=m; column++){
				char c;
				cin>>c;
				if (c=='x') forest[row][column]=true;
			}
		}
		calc();
	}
}
