#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool mp[1024][1024];
bool sign[1024][1024];

void go(){
	int nx=x+dx[z],ny=y+dy[z];
	if(nx<n&&nx>=0&&ny<m&&ny>=0&&mp[nx][ny]==0){
		x = nx;
		y = ny;
	}else{
		z = (z+1)%4;
	}
	return;
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(mp,0,sizeof(mp));
		memset(sign,0,sizeof(sign));
		int k,cnt = 0;
		cin>>n>>m>>k>>x>>y>>z;
		x--;y--;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				char c;
				cin>>c;
				if(c=='.') mp[i][j]=0;
				else if(c=='x') mp[i][j]=1;
			}
		}
		cnt++;
		sign[x][y]=1;
		while(k--){
			go();
			if(sign[x][y]==0){
				cnt++;
				sign[x][y]=1;
			}
		}
		cout<<cnt<<endl;
	}
	return 0; 
}
