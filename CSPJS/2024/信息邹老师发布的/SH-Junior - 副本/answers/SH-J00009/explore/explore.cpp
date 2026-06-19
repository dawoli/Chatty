#include <bits/stdc++.h>
using namespace std;
long long  T,n,m,k;
long long  x,y,d;//d=0代表向东,d=1 代表向南，d=2代表向西，d = 3 代表向北。
int cnt=0;
char a[1000][1000];
int stl[1000][1000];//0表示没走过，1表示走过 
void xunlu(int k,int x,int y,int d){
	if(k<=0){
		return ;
	}
	if(d==0){
		if(a[x][y+1]!='x' && y+1<=m){
			y+=1;
			k--;
			if(stl[x][y]==0){
				stl[x][y]=1;
			}
//			cout<<x<<" "<<y<<endl;
//			cout<<k<<endl;
			xunlu(k,x,y,d); 
		}
		else{
			d=1;
			k--;
//			cout<<x<<" "<<y<<endl;
//			cout<<k<<endl;
			xunlu(k,x,y,d);
		}
	}
	if(d==1){
		if(a[x+1][y]!='x' && x+1<=n){
			x+=1;
			k--;
			if(stl[x][y]==0){
				stl[x][y]=1;
			}
//			cout<<x<<" "<<y<<endl;
//			cout<<k<<endl;
			xunlu(k,x,y,d);
		}
		else{
			d=2;
			k--;
//			cout<<x<<" "<<y<<endl;
//			cout<<k<<endl;
			xunlu(k,x,y,d);
		}
	}
	if(d==2){
		if(a[x][y-1]!='x' && y-1>=1){
			y-=1;
			k--;
			if(stl[x][y]==0){
				stl[x][y]=1;
			}
//			cout<<x<<" "<<y<<endl;
//			cout<<k<<endl;
			xunlu(k,x,y,d);
		}
		else{
			d=3;
			k--;
//			cout<<x<<" "<<y<<endl;
//			cout<<k<<endl;
			xunlu(k,x,y,d);
		}
	}
	if(d==3){
		if(a[x-1][y]!='x' && x-1>=1){
			x-=1;
			k--;
			if(stl[x][y]==0){
				stl[x][y]=1;
			}
//			cout<<x<<" "<<y<<endl;
//			cout<<k<<endl;
			xunlu(k,x,y,d);
		}
		else{
			d=0;
			k--;
//			cout<<x<<" "<<y<<endl;
//			cout<<k<<endl;
			xunlu(k,x,y,d);
		}
	}
}
int main(){
	freopen("exlpore.in","r",stdin);
	freopen("exlpore.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		cnt=0;
		memset(stl,0,sizeof stl);
		memset(a,' ',sizeof a);
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for(int i=1;i<n+1;i++){
			for(int j=1;j<m+1;j++){
				cin>>a[i][j];
			}
		}
		stl[x][y]=1;
		xunlu(k,x,y,d);
		for(int i=1;i<=n+1;i++){
			for(int j=1;j<=m+1;j++){
				if(stl[i][j]==1)
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
