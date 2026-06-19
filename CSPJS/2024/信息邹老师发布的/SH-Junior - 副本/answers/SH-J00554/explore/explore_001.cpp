#include<bits/stdc++.h>
using namespace std;

int t,n,m,k;

char s[1003][1003];

bool check(int x,int y){
	if(x<=0||x>n||y<=0||y>m) return false;
	if(s[x][y]=='x') return false;
	else return true;
}

void dfs(int dep,int x,int y,int d){
	if(dep>k) return;
//	if(!check(x,y)) return;
	int a=x,b=y;
	switch (d){
		case 0:{
			y++;
			break;
		}
		case 1:{
			x++;
			break;
		}
		case 2:{
			y--;
			break;
		}
		case 3:{
			x--;
			break;
		}
	}

	if(!check(x,y)){
		x=a;
		y=b;
		d=(d+1)%4;
	}
	else{
		s[x][y]='a';
	}
	
	//printf("x:%d y:%d d:%d s:%c\n",x,y,d,s[x][y]);
	
	dfs(dep+1,x,y,d);
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	int x,y,d;
	cin>>t;
	
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>s[i][j];
			}
		}
		dfs(1,x,y,d);
		int ans=1;
	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i][j]=='a') ans++;
				//cout<<s[i][j];
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}

	return 0;
}
