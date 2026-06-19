#include<bits/stdc++.h>

using namespace std;

bool a[1010][1010]; // a[x][y] == 1表示当前位置是空地，否则表示是障碍 
bool p[1010][1010]; // p[i][j] 表示当前位置是否到达过 

int n,m,k;
int x,y,d;

bool ahead(){ // 获取当前朝向向前一格的情况 
	if(d == 0) return a[x][y+1];
	else if(d == 1) return a[x+1][y];
	else if(d == 2) return a[x][y-1];
	else if(d == 3) return a[x-1][y];
}

void turn(){ // 转向 
	do{
		k --;
		d = (d+1)%4;
	}while(!ahead());
} // 转向逻辑：转到面前为空地为止

void go(){ // 直行 
	while(k > 0 && ahead()){
		k--;
		if(d == 0) y++;
		else if(d == 1) x++;
		else if(d == 2) y--;
		else if(d == 3) x--;
		p[x][y] = 1;
	}
} // 直行逻辑：直走到下一步不合理，即 !ahead() 
 
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	int t; cin >> t;
	
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				a[i][j] = 0; // 全部设为不可达（避免上组数据导致的额外空地） 
				p[i][j] = 0; // 初始化到达情况（避免上组数据的重复计数） 
			}
		}
		
		for(int i = 1; i <= n; i ++){
			char opt;
			scanf("%c",&opt);
			for(int j = 1; j <= m; j ++){
				scanf("%c",&opt);
				a[i][j] = (opt == '.'); 
			}
		} // 读入 
		p[x][y] = 1; // 初始位置一定到达过 
		
		while(k > 0){
			if(!ahead()) turn();
			else go();
		}
		
		int cnt = 0;
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				cnt += p[i][j];
			}
		}
		printf("%d\n",cnt);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
