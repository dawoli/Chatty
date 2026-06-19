#include<bits/stdc++.h>
using namespace std;
char p[1005][1005];
int cnt[5];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int r=1;r<=t;r++){	
    bool s[1005][1005];
    for(int i=1;i<=1000;i++)
    for(int j=1;j<=1000;j++)
    s[i][j]=false;
	int n,m,k,x,y,d;
	cin>>n>>m>>k;
	cin>>x>>y>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>p[i][j];
		}
	}//以上输入矩阵 
	s[x][y]=true; //走过的即为1，反之为0 
	while(k>0){//循环k次 
		
		int n1,n2;
		if(d==0) {
			n1=x,n2=y+1;
		}
	    else if(d==1){
			n1=x+1,n2=y;
		}
	    else if(d==2){
			n1=x,n2=y-1;
		}
	    else if(d==3){
			n1=x-1,n2=y;//n1,n2为下一步的位置 
		}//此处判断下一步该怎么走 
		if(p[n1][n2]=='.'&&n1<=n&&n2<=m&&1<=n1&&1<=n2){//如果是空地而且在地图内 
			s[n1][n2]=1;// 记为走过 
			x=n1,y=n2;//走过去 
		}
		
        //if(p[n1][n2]=='x'||n1>n||n2>m||n1<1||n2<1)
		else{
			d=(d+1)%4;//右转弯 
		}//模拟走路的操作 
		k--;//循环次数减一 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==1)
			cnt[r]++;
		}
	}
	
	cout<<cnt[r]<<endl;}
	return 0;
}
