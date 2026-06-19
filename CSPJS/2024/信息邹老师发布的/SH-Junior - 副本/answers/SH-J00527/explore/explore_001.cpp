#include<bits/stdc++.h>
using namespace std;

int t;
int n,m,k,x,y,d;
char forest[1005][1005];
bool iw[1005][1005];
int dxy[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int func(){
	int ans = 1;
	int i = 0;
	while(i<=k){
		int tx = x + dxy[d][0];
		int ty = y + dxy[d][1];
		while(tx>n||tx<1||ty>m||ty<1||forest[tx][ty]=='x'){
			d = (d+1) % 4;
			tx = x + dxy[d][0];
			ty = y + dxy[d][1];
			i++;
		}
		if(!iw[tx][ty]){
			ans++;
			iw[tx][ty] == true;
		}
		x = tx;
		y = ty;
	} 
	return ans;
}

int main(){
	freopen("explore","r",stdin);
	freopen("explore","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				cin>>forest[j][l];
				iw[j][l] = false;
			}
		}
		iw[x][y] = true;
		cout<<func()<<endl;
	}
	return 0;
} 
