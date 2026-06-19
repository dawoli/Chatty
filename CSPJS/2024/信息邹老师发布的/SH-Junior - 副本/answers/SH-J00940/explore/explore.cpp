#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,cnt=1;
bool v[1010][1010]={};
bool v1[1010][1010]={};
void dfs(int x,int y,int d){
	if(k==0)return;
	if(d==0){
		if(x>=1&&x<=n&&y+1>=1&&y+1<=m&&v[x][y+1]==true){
			k--;
			if(v1[x][y+1]==false){
				cnt++;
				v1[x][y+1]=true;
		    }
			dfs(x,y+1,d);
		}else{
			k--;
			dfs(x,y,(d+1)%4);
		}
	}else if(d==1){
		if(x+1>=1&&x+1<=n&&y>=1&&y<=m&&v[x+1][y]==true){
			k--;
			if(v1[x+1][y]==false){
				cnt++;
				v1[x+1][y]=true;
		    }
			dfs(x+1,y,d);
		}else{
			k--;
			dfs(x,y,(d+1)%4);
		}
	}else if(d==2){
		if(x>=1&&x<=n&&y-1>=1&&y-1<=m&&v[x][y-1]==true){
			k--;
			if(v1[x][y-1]==false){
				cnt++;
				v1[x][y-1]=true;
		    }
			dfs(x,y-1,d);
		}else{
			k--;
			dfs(x,y,(d+1)%4);
		}
	}else if(d==3){
		if(x-1>=1&&x-1<=n&&y>=1&&y<=m&&v[x-1][y]==true){
			k--;
			if(v1[x-1][y]==false){
				cnt++;
				v1[x-1][y]=true;
		    }
			dfs(x-1,y,d);
		}else{
			k--;
			dfs(x,y,(d+1)%4);
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int x,y,d;
	scanf("%d",&t);
	for(int l=1;l<=t;l++){
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for(int i=1;i<=n;i++){
			string x1;
			cin>>x1;
			for(int j=1;j<=m;j++){
				if(x1[j-1]=='.'){
					v[i][j]=true;
				}
			}
		}
		v1[x][y]=true;
		dfs(x,y,d);
		cout<<cnt<<endl;
		cnt=1;
		memset(v,false,sizeof(v));
		memset(v1,false,sizeof(v1));
	}
	return 0;
}
