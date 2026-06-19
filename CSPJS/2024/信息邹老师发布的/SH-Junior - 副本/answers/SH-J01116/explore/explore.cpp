#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
char a[1005][1005];
bool vis[1005][1005];
void f(int x,int y,int d,int dep){
	if(dep>=k){
		return;
	}
	int new_x=x,new_y=y,flag=0;
	if(d==0){
		new_y++;
	}else if(d==1){
		new_x++;
	}else if(d==2){
		new_y--;
	}else{
		new_x--;
	}
	if(new_x<1||new_y<1||new_x>n||new_y>m){
	//	cout<<"a\n";
		flag=1;
	}else if(a[new_x][new_y]=='x'){
	//	cout<<"b\n";
		flag=1;
	}//cout<<x<<" "<<y<<" "<<dep<<" "<<flag<<endl;
	if(flag==0){
//		cout<<x<<" "<<y<<" "<<dep<<" "<<flag<<endl;
		vis[new_x][new_y]=1;
		f(new_x,new_y,d,dep+1);
	}else{
		d=(d+1)%4;
		f(x,y,d,dep+1);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	for(int _i=1;_i<=t;_i++){
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}

		}
		vis[x][y]=1;
		f(x,y,d,0);	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
			//	cout<<vis[i][j]<<" ";
				if(vis[i][j]==1){
					ans++;
				}
			}//cout<<"\n";
		}printf("%d\n",ans);	
	}
	
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....

*/	
	return 0;
}
