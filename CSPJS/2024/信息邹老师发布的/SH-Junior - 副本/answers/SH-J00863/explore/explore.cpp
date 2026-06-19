#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,answ;
int x0,y0,d0;
bool maps[1001][1001],steps[1001][1001];
queue<int>ans;
bool judge(int x,int y,int d){
	if(d==0)y++;
	else if(d==1)x++;
	else if(d==2)y--;
	else if(d==3)x--;
	if(1<=x && 1<=y && x<=n && y<=m && !maps[x][y])return true;
	else return false;
}
void go(int x,int y,int d,int step){
	//printf("\n%d %d %d",x,y,d);
	if(!steps[x][y]){
		steps[x][y]=true;
		answ++;
	}
	if(step==k)return;
	if(!judge(x,y,d))go(x,y,(d+1)%4,step+1);
	else{
		if(d==0)y++;
		else if(d==1)x++;
		else if(d==2)y--;
		else if(d==3)x--;
		go(x,y,d,step+1);
	}
	return;
}
void init(){
	char c;
	scanf("%d",&t);
	while(t--){
		answ=0;
		memset(maps,0,sizeof(maps));
		memset(steps,0,sizeof(steps));
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x0,&y0,&d0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c;
				if(c=='x')maps[i][j]=true;
			}
		}
		//cout<<k;
		go(x0,y0,d0,0);
		ans.push(answ);
		/*
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<steps[i][j];
			}
			puts("");
		}
		*/
	}
}
void print(){
	while(!ans.empty()){
		printf("%d\n",ans.front());
		ans.pop();
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	init();
	print();
	return 0;
}
