#include<bits/stdc++.h>
using namespace std;
struct robots{
	int x,y,d;
};
int yd[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int m,n,k;
robots robot;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
    	cin>>m>>n>>k;
    	bool flag[1005][1005]={false};
        char map[n+5][m+5];
    	int sum=0;
    	cin>>robot.x>>robot.y>>robot.d;
    	flag[robot.x][robot.y]=true;
    	for(int i=1;i<=m;i++){
    		for(int j=1;j<=n;j++){
    			cin>>map[i][j];
			}
		}
		int d=robot.d,x=robot.x,y=robot.y;
    	for(int i=1;i<=k;i++){
	    	int xx,yy;
	    	xx=x+yd[d][0],yy=y+yd[d][1];
	    	if(xx<=0 || yy<=0 || xx>m || yy>n || map[xx][yy]=='x'){
	    	    d=(d+1)%4;
	    	}else{
	    		x=xx,y=yy;
	    		flag[x][y]=true;
		    }
//		    cout<<x<<" "<<y<<" "<<d<<" "<<flag[x][y]<<endl;
    	}
	    for(int i=1;i<=m;i++){
		    for(int j=1;j<=n;j++){
			    if(flag[i][j]){
				    sum++;
    			}
    		}
	    }
    	cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

